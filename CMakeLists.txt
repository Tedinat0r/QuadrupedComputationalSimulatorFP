set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.31)
project(QuadrupedSimulator)

add_executable(QuadrupedSimulator main.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/PipelineComponent.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/PipelineComponent.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/Processor.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/Processor.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Validators/Validator.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Validators/Validator.h
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/ConverterTracker.h
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/PipelineOrchestrator.cpp
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/PipelineOrchestrator.h
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/DLQScheduler.cpp
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/DLQScheduler.h
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListenerQueue.cpp
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListenerQueue.h
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListener/ValidatorListener.h
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListener/ConcreteValidatorListener.cpp
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/ValidatorListener/ConcreteValidatorListener.h
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/ProgressTracker/Tracker.h
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/ProgressTracker/Bodies.h
        src/SKELConverter/ConversionPipeline/PipelineOrchestrator/ProgressTracker/Joint.h
        src/SKELConverter/ConversionPipeline/Message/Message.cpp
        src/SKELConverter/ConversionPipeline/Message/Message.h
        src/SKELConverter/ConversionPipeline/Message/ValidatorStatusMessage.cpp
        src/SKELConverter/ConversionPipeline/Message/ValidatorStatusMessage.h
        src/SKELConverter/ConversionPipeline/CPipeline.cpp
        src/SKELConverter/ConversionPipeline/CPipeline.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/BodyProcessor.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/BodyProcessor.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/OBJParser.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/OBJParser.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/HeaderParser.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/HeaderParser.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/BlockerParser.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/Parsers/BlockerParser.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/DataVisitor.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/DataVisitor.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/FaceAssembler.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/FaceAssembler.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/GraphMaker.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/DataVisitors/GraphMaker.h
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/BoundingBox/BoundingBox.h

)

target_include_directories(QuadrupedSimulator PRIVATE C:/Users/teddy/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/include
PRIVATE C:/Users/teddy/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/share)
set(Catch2_DIR C:/Users/teddy/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/share/catch2)
find_package(Catch2 CONFIG REQUIRED)

add_subdirectory(tests)

