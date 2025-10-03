//
// Created by teddy on 30/09/2025.
//

#ifndef CONVERSIONPIPELINE_H
#define CONVERSIONPIPELINE_H
#include "PipelineOrchestrator/PipelineOrchestrator.h"

namespace ConversionPipeline {
template<typename obj, typename T>
class ConversionPipeline {
private:
    PipelineOrchestrator<obj, T> orchestrator;
    
};

} // ConversionPipeline

#endif //CONVERSIONPIPELINE_H
