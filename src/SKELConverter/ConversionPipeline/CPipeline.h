//
// Created by teddy on 30/09/2025.
//

#ifndef CPIPELINE_H
#define CPIPELINE_H
#include "PipelineOrchestrator/PipelineOrchestrator.h"
#include "PipelineComponents/Validators/Validator.h"
#include "PipelineComponents/PipelineComponent.h"
#include <vector>
using std::vector;


namespace ConversionPipeline {
class CPipeline {
private:
    PipelineOrchestrator orchestrator;
    vector<PipelineComponent> components;
    vector<Validator> validators;
    vector<ValidatorListener> listeners;
public:
    CPipeline() = default;
    void buildPipeline();
};

} // ConversionPipeline

#endif //CPIPELINE_H
