cmake_minimum_required(VERSION 3.31)
project(QuadrupedSimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(QuadrupedSimulator main.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/PipelineComponent.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/PipelineComponent.h
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/Processor.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/Processor.h
        SKELConverter/ConversionPipeline/PipelineComponents/Validators/Validator.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/Validators/Validator.h
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ConverterTracker.h
        SKELConverter/ConversionPipeline/PipelineOrchestrator/PipelineOrchestrator.cpp
        SKELConverter/ConversionPipeline/PipelineOrchestrator/PipelineOrchestrator.h
        SKELConverter/ConversionPipeline/PipelineOrchestrator/DLQScheduler.cpp
        SKELConverter/ConversionPipeline/PipelineOrchestrator/DLQScheduler.h
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListenerQueue.cpp
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListenerQueue.h
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListener/ValidatorListener.cpp
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListener/ValidatorListener.h
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListener/ConcreteValidatorListener.tpp
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListener/ConcreteValidatorListener.h
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ProgressTracker/Tracker.h
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ProgressTracker/Bodies.h
        SKELConverter/ConversionPipeline/PipelineOrchestrator/ProgressTracker/Joint.h
        SKELConverter/ConversionPipeline/Message/Message.cpp
        SKELConverter/ConversionPipeline/Message/Message.h)
