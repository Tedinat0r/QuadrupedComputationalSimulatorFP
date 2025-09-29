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
    template <typename obj, typename T>
    class PipelineOrchestrator {
    private:
        ValidatorListenerQueue<ConcreteValidatorListener<T, obj>, T> validatorListenerQueue;
        std::map<std::string, ProgressTracker> trackers;
        std::map<std::string, bool> pipelineComponentStatuses = {
            {"bodyParsing", false},
            {"jointDetection", false},
            {"romCalculator", false},
            {"mmCalculator", false}
        };
        std::map<std::string, std::list<ValidatorStatusMessage<obj>>> validatorStatuses = {
            {"bodyParsing", new std::list<ValidatorStatusMessage<obj>>},
            {"jointDetection", new std::list<ValidatorStatusMessage<obj>>},
            {"romCalculator", new std::list<ValidatorStatusMessage<obj>>},
            {"mmCalculator", new std::list<ValidatorStatusMessage<obj>>}
        };
        std::vector<std::string> keyIndexes = {"bodyParsing", "jointDetection", "romCalculator", "mmCalculator"};
        /* Micro functions*/
        void makeTracker(std::string id);
        void updateTracker(ValidatorStatusMessage<obj> message);
        ConcreteValidatorListener<T, obj> readQueue();
        /* Macro functions */
        void progressPipeline();
    public:

    };
} // ConversionPipeline

#endif //PIPELINEORCHESTRATOR_H
