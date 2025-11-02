//
// Created by teddy on 21/09/2025.
//

#include "PipelineOrchestrator.h"
#include "../PipelineComponents/Validators/Validator.h"

#include <ranges>
#include <boost/pfr.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace std;

namespace ConversionPipeline {
    void PipelineOrchestrator::makeTracker(std::string id) {
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
    void PipelineOrchestrator::updateTracker(Message* message) {
        string trackerId = message->metadata["trackerID"];
        int part = this->partSwitchMap[message->metadata["affectedBody"]];
        int process = this->processSwitchMap[message->metadata["process"]];

        Bodies* trackerBodies = &this->trackers[trackerId].bodies;
        Body* targetBody;

        switch (part) {
            case 0: {
                targetBody = boost::pfr::get<0>(trackerBodies);
            }
            case 1: {
                targetBody = boost::pfr::get<1>(trackerBodies);
            }
            case 2: {
                targetBody = boost::pfr::get<2>(trackerBodies);
            }
            case 3: {
                targetBody = boost::pfr::get<3>(trackerBodies);
            }
            case 4: {
                targetBody = boost::pfr::get<4>(trackerBodies);
            }
            default: {
                raise(1);
            }
        };
        switch (process) {
            case 0: {
                targetBody.isParsed = true;
            }
            case 1: {
                /*writing logic once jointParser is written*/
                vector<Joint> bodyJoints = targetBody.Joints;
                /*add an exception block*/
                targetBody.hasJoints = true;
            }
            case 2: {
                /* Add joint struct access logic */
            }
            case 3: {
                targetBody.hasMass = true;
                targetBody.hasMaterials = true;
            }
            default: {
                raise(1);
            }
        }
    };
    void PipelineOrchestrator::destroyTracker(std::string id) {
        this->trackers.erase(id);
    }

    ConcreteValidatorListener* PipelineOrchestrator::readQueue(){
        ConcreteValidatorListener listener = this->validatorListenerQueue.Listeners.front();
        ConcreteValidatorListener* currentListener = &listener;
        return currentListener;
    };

    void PipelineOrchestrator::progressPipeline() {
        ConcreteValidatorListener* currentListener = this->readQueue();
        Message* message = currentListener->message;
        this->updateTracker(message);
        string process = message->metadata["process"];
        this->pipelineComponentStatuses[process] = false;
        Validator* validator = currentListener->validator;
        Message valMessage = *validator->getState();
        unique_ptr<Message> validatorState = make_unique<Message>(valMessage);
        /*Insert cache bus logic, transfer state*/
        if (process != "mmCalculator") {
            string nextProcess;
            for (int i = 1; i < 4; i++) {
                if (this->processKeyIndexes[i-1] == process) {
                    nextProcess = this->processKeyIndexes[i];
                }
            }
            /*If next process has tasks in queue, takes passed process and adds to queue, sends 1st item in que
             *to next pipeline component
             */
            if (!this->validatorStatuses[nextProcess].empty()) {
                validator->flush();
                /*!!!-\ Ptr rediriection /-!!!*/
                std::list<std::unique_ptr<Message>>* validator_status = &this->validatorStatuses[nextProcess];
                if (validator_status->front() == nullptr) {
                    validator_status->pop_front();
                }
                validator_status->back() = std::move(validatorState);
                validator->setState(std::move(validatorStatuses[nextProcess].front()));
                validator->releaseState();
                validatorStatuses[nextProcess].erase(validatorStatuses[nextProcess].begin());
            }else {
                validator->releaseState();
            }
        }else {
            /*Tracker parsing logic */
            std::string id = message->metadata["trackerID"];
            this->destroyTracker(id);
        }
        ConcreteValidatorListener listener = this->validatorListenerQueue.Listeners.front();
        this->validatorListenerQueue.Listeners.pop_front();
        this->validatorListenerQueue.Listeners.push_back(listener);
    }

    bool PipelineOrchestrator::checkQueues() {
        for (bool value : std::ranges::views::values(this->pipelineComponentStatuses)) {
            if (value == true) {
                return false;
            }
            /*auto vsValues = std::ranges::views::values(this->validatorStatuses);
            int vsOccupied = std::ranges::count_if(vsValues.begin(), vsValues.end(), [](auto const list) { return list.size() > 0; });
            if (vsOccupied != 0) {
                return false;
            }*/
            for(const auto& list : std::ranges::views::values(this->validatorStatuses)){
                if (!list.empty()) {
                    return false;
                }
            }
            if (!this->trackers.empty()) {
                return false;
            }
        };
        return true;
    }
    void PipelineOrchestrator::runEventLoop() {
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

    PipelineOrchestrator::PipelineOrchestrator() {
        std::list<std::unique_ptr<Message>> bpList;
        bpList.push_back(std::make_unique<Message>());
        std::list<std::unique_ptr<Message>> jdList;
        jdList.push_back(std::make_unique<Message>());
        std::list<std::unique_ptr<Message>> romCList;
        romCList.push_back(std::make_unique<Message>());
        std::list<std::unique_ptr<Message>> mmCList;

        this->validatorStatuses.insert(std::make_pair("bodyParsing", std::move(bpList)));
        this->validatorStatuses.insert(std::make_pair("jointDetection", std::move(jdList)));
        this->validatorStatuses.insert(std::make_pair("romCalculator", std::move(romCList)));
        this->validatorStatuses.insert(std::make_pair("mmCalculator", std::move(mmCList)));




    }


}


