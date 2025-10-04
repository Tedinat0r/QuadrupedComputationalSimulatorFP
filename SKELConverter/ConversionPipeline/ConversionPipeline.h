//
// Created by teddy on 30/09/2025.
//

#ifndef CONVERSIONPIPELINE_H
#define CONVERSIONPIPELINE_H
#include "PipelineOrchestrator/PipelineOrchestrator.h"
#include "Message/Message.h"
#include "PipelineComponents/Validators/Validator.h"
#include "PipelineComponents/PipelineComponent.h"
#include "PipelineComponents/Processors/Processor.h"
#include "PipelineOrchestrator/ProgressTracker/Tracker.h"
#include "PipelineOrchestrator/PipelineOrchestrator.h"
#include <vector>
using std::vector;


namespace ConversionPipeline {
template<typename obj, typename T>
class ConversionPipeline {
private:
    PipelineOrchestrator<obj, T> orchestrator;
    vector<PipelineComponent<T>> components;
    vector<Validator<T, obj>> validators;
    vector<ValidatorListener<obj>> listeners;
    void buildPipeline();
};

} // ConversionPipeline

#endif //CONVERSIONPIPELINE_H
