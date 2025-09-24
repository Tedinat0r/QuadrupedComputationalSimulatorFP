//
// Created by teddy on 21/09/2025.
//

#ifndef PIPELINEORCHESTRATOR_H
#define PIPELINEORCHESTRATOR_H
#include <map>
#include <string>
#include "ValidatorListenerQueue.h"
#include "../Message/ValidatorStatusMessage.h"
#include "ProgressTracker/Tracker.h"

namespace ConversionPipeline {
    template <typename obj>
    class PipelineOrchestrator {
    private:
        ValidatorListenerQueue<ConcreteValidatorListener<std::string>> validatorListenerQueue;
        std::map<std::string, ProgressTracker> trackers;

        void makeTracker(std::string id);
        void updateTracker(ValidatorStatusMessage<obj> message);
        void progressPipeline();
    public:

    };
} // ConversionPipeline

#endif //PIPELINEORCHESTRATOR_H
