//
// Created by teddy on 21/09/2025.
//

#ifndef PIPELINEORCHESTRATOR_H
#define PIPELINEORCHESTRATOR_H
#include <string>
#include "ValidatorListenerQueue.h"
#include "ProgressTracker/Tracker.h"
#include <map>

namespace ConversionPipeline {
    class PipelineOrchestrator {
    private:
        ValidatorListenerQueue<ConcreteValidatorListener<std::string>> validatorListenerQueue;
        std::map<std::string, ProgressTracker> trackers;

        void makeTracker(std::string id);
        void initListenerQueue() {

        }
    public:

    };
} // ConversionPipeline

#endif //PIPELINEORCHESTRATOR_H
