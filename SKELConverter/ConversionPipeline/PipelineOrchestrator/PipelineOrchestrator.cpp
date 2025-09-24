//
// Created by teddy on 21/09/2025.
//

#include "PipelineOrchestrator.h"
#include <boost/pfr.hpp>
using namespace std;

namespace ConversionPipeline {
    template <typename obj>
    void PipelineOrchestrator<obj>::makeTracker(std::string id) {
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
    template<typename obj>
    void PipelineOrchestrator<obj>::updateTracker(ValidatorStatusMessage<obj> message) {
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
    }
    template<typename obj>
    void PipelineOrchestrator<obj>::progressPipeline() {

    }


}


