
add_executable(tests BodyProcessors/UnitTests/UnitTests.cpp)
target_include_directories(tests PRIVATE src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/BodyProcessor.cpp
        src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/BodyProcessor.h)

find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain
)