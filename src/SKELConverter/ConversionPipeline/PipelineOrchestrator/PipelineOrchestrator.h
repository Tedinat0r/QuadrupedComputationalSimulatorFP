//
// Created by teddy on 21/09/2025.
//

#ifndef PIPELINEORCHESTRATOR_H
#define PIPELINEORCHESTRATOR_H
#include <map>
#include <memory>
#include <string>
#include "ValidatorListenerQueue.h"
#include "../Message/ValidatorStatusMessage.h"
#include "ProgressTracker/Tracker.h"

namespace ConversionPipeline {
    class PipelineOrchestrator {
    private:
        ValidatorListenerQueue validatorListenerQueue;
        std::map<std::string, ProgressTracker> trackers;
        std::map<std::string, bool> pipelineComponentStatuses = {
            {"bodyParsing", false},
            {"jointDetection", false},
            {"romCalculator", false},
            {"mmCalculator", false}
        };
        /*Replace message template with OBJ wrapper*/
        std::map<std::string, std::list<std::unique_ptr<Message>>> validatorStatuses;
        std::map<std::string, int> partSwitchMap = {
            {"torso", 0},
            {"shoulderF", 1},
            {"shoulderB", 2},
            {"legsFront", 3},
            {"legsBack", 4}
        };
        std::map<std::string, int> processSwitchMap = {
            {"bodyParsing", 0},
            {"jointDetection", 1},
            {"romCalculator", 2},
            {"mmCalculator", 3}
        };
        std::vector<std::string> partsKeyIndexes = {"torso", "shoulderF", "shoulderB", "legsFront", "legsBack"};
        std::vector<std::string> processKeyIndexes = {"bodyParsing", "jointDetection", "romCalculator", "mmCalculator"};
        std::list<std::string> cleanupQueue = {};
        /* Micro functions*/
        void destroyTracker(std::string id);
        ConcreteValidatorListener* readQueue();
        /* Macro functions */
        void progressPipeline();
        bool checkQueues();
    public:
        std::list<vector<vector<float>>> objs;
        void runEventLoop();
        void makeTracker(std::string id);
        void updateTracker(Message* message);

        PipelineOrchestrator();
    };
} // ConversionPipeline

#endif //PIPELINEORCHESTRATOR_H
