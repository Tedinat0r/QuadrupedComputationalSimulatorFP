//
// Created by teddy on 21/09/2025.
//

#include "PipelineOrchestrator.h"

#include <ranges>
#include <boost/pfr.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace std;

namespace ConversionPipeline {
    template <typename obj, typename T>
    void PipelineOrchestrator<obj, T>::makeTracker(std::string id) {
        Body torso = Body(
            false,
            false,
            false,
            false
        );
        Body shoulderF = Body(
            false,
            false,
            false,
            false
        );
        Body shoulderB = Body(
            false,
            false,
            false,
            false
        );
        Body legsFront = Body(
            false,
            false,
            false,
            false
        );
        Body legsBack = Body(
            false,
            false,
            false,
            false
        );
        Bodies trackerBodies = Bodies(
            torso,
            shoulderF,
            shoulderB,
            legsFront,
            legsBack
            );
        ProgressTracker tracker = ProgressTracker(
            trackerBodies,
            id,
            "",
            false);
        this->trackers.insert({id, tracker});
    }
    template<typename obj, typename T>
    void PipelineOrchestrator<obj, T>::updateTracker(ValidatorStatusMessage<obj> message) {
        string trackerId = message.metadata["trackerID"];
        string part = message.metadata["affectedBody"];
        string process = message.metadata["process"];

        Bodies trackerBodies = this->trackers[trackerId].bodies;
        Body targetBody;
            switch (part) {
                case "torso":
                    targetBody = boost::pfr::get<0>(trackerBodies);
                case "shoulderF":
                    targetBody = boost::pfr::get<1>(trackerBodies);
                case "shoulderB":
                    targetBody = boost::pfr::get<2>(trackerBodies);
                case "legsFront":
                    targetBody = boost::pfr::get<3>(trackerBodies);
                case "legsBack":
                    targetBody = boost::pfr::get<4>(trackerBodies);
                default:
                    raise(1);
                }
            switch (process) {
                case "bodyParsed":
                    targetBody.isParsed = true;
                    case "jointsParsed":
                    /*writing logic once jointParser is written*/
                    vector<Joint> bodyJoints = targetBody.Joints;
                    /*add an exception block*/
                    targetBody.hasJoints = true;
                    case "romCalculator":
                    /* Add joint struct access logic */
                    return;
                    case "mmCaclulator":
                    targetBody.hasMass = true;
                    targetBody.hasMaterials = true;
            }
    };
    template<typename obj, typename T>
    void PipelineOrchestrator<obj, T>::destroyTracker(std::string id) {
        this->trackers.erase(id);
    }



    template<typename obj, typename T>
    ConcreteValidatorListener<T, obj>* PipelineOrchestrator<obj, T>::readQueue(){
        ConcreteValidatorListener<T, obj> *currentListener = this->validatorListenerQueue.Listeners.front;
        return currentListener;
    };

    template<typename obj, typename T>
    void PipelineOrchestrator<obj, T>::progressPipeline() {
        ConcreteValidatorListener<T, obj>* currentListener = this->readQueue();
        ValidatorStatusMessage<obj> message = currentListener.message;
        this->updateTracker(message);
        string process = message.metadata["process"];
        this->pipelineComponentStatuses[process] = false;
        Validator<T, obj> validator = currentListener.validator;
        T validatorState  = validator.template state<T>;
        /*Insert cache bus logic, transfer state*/
        if (process != "mmCalculator") {
            string nextProcess;
            for (int i = 1; i < 4; i++) {
                if (this->keyIndexes[i-1] == process) {
                    nextProcess = this->keyIndexes[i];
                }
            }
            /*If next process has tasks in queue, takes passed process and adds to queue, sends 1st item in que
             *to next pipeline component
             */
            if (!this->validatorStatuses[nextProcess].empty()) {
                validator.flush();
                this->validatorStatuses[nextProcess].push_back(validatorState);
                validator.state = validatorStatuses[nextProcess].front();
                validator.releaseState();
                validatorStatuses[nextProcess].erase(validatorStatuses[nextProcess].begin());
            }else {
                validator.releaseState();
            }
        }else {
            /*Tracker parsing logic */
            std::string id = message.metadata["trackerID"];
            this->destroyTracker(id);
        }
        this->validatorListenerQueue.Listeners.push_back(this->validatorListenerQueue.Listeners.pop_front());
    }

    template<typename obj, typename T>
    bool PipelineOrchestrator<obj, T>::checkQueues() {
        for (bool value : std::ranges::views::values(this->pipelineComponentStatuses)) {
            if (value == true) {
                return false;
            }
        for (std::list<ValidatorStatusMessage<obj>> list : std::ranges::views::values(this->validatorStatuses)){
            if (!list.empty()) {
                return false;
            }
        }
        if (!this->trackers.empty()) {
            return false;
        }
        return true;
        };
    }
    template<typename obj, typename T>
    void PipelineOrchestrator<obj, T>::runEventLoop() {
        while (!this->checkQueues()) {
            if (!this->pipelineComponentStatuses["bodyParsing"]) {
                /*Logic for adding new obj file to cache/pipeline
                 *
                 *
                 *
                 */
                boost::uuids::random_generator gen;
                boost::uuids::uuid uuid = gen();
                std::string id = boost::uuids::to_string(uuid);
                this->makeTracker(id);

            }
            this->progressPipeline();


        }
    }





}


