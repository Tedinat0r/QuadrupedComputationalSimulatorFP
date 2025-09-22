//
// Created by teddy on 21/09/2025.
//

#include "PipelineOrchestrator.h"

namespace ConversionPipeline {
    void PipelineOrchestrator::makeTracker(std::string id) {
        Body torso = Body(
            false,
            false,
            false
        );
        Body shoulderF = Body(
            false,
            false,
            false
        );
        Body shoulderB = Body(
            false,
            false,
            false
        );
        Body legsFront = Body(
            false,
            false,
            false
        );
        Body legsBack = Body(
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

}


