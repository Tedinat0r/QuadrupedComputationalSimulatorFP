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
        SKELConverter/ConversionPipeline/Message/Message.h
        SKELConverter/ConversionPipeline/Message/ValidatorStatusMessage.cpp
        SKELConverter/ConversionPipeline/Message/ValidatorStatusMessage.h
        SKELConverter/ConversionPipeline/ConversionPipeline.cpp
        SKELConverter/ConversionPipeline/ConversionPipeline.h
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/BodyProcessor.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/BodyProcessor.h
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/OBJParser.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/OBJParser.h
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/HeaderParser.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/HeaderParser.h
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/BlockerParser.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/BlockerParser.h
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/DataVisitor.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/DataVisitor.h
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/FaceAssembler.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/FaceAssembler.h
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/GraphMaker.cpp
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/GraphMaker.h
        SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/BoundingBox/BoundingBox.h
)

target_include_directories(QuadrupedSimulator PRIVATE  C:/Users/teddy/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/include)
