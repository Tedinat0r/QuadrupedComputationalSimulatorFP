//
// Created by teddy on 04/10/2025.
//

#include <iostream>

#include "../../ConversionPipeline.h"
#include <vector>
#include "../../PipelineComponents/PipelineComponent.cpp"

using namespace ConversionPipeline;
using std::vector;

template<typename T>
vector<PipelineComponent<T>> buildBasicPipeline() {
    vector<PipelineComponent<T>> pipelineComponents;
    for (int i = 0; i < 5; i++) {
        pipelineComponents.push_back(PipelineComponent<T>());
    }
    std::cout << pipelineComponents.size() << std::endl;
    for (int i = 0; i < pipelineComponents.size() - 1; i++) {
        PipelineComponent<T>* ptr = &pipelineComponents[i+1];
        PipelineComponent<T> current = pipelineComponents[i];
        current.joinOutput(ptr);
    }

    return pipelineComponents;
}

template<typename T>
bool baseAssemblyTest() {
    vector<PipelineComponent<T>> pipelineComponents = buildBasicPipeline<T>();
    PipelineComponent<T> entry = pipelineComponents[0];
    int index = 1;
    while (true) {
        if (entry.output != &pipelineComponents[index]) {
            return false;
        }
        if (entry.output == &pipelineComponents[pipelineComponents.size() - 1]) {
            break;
        }
        entry = *entry.output;
        index++;
    }
    return true;

}

bool basicFlowTest() {
    int state = 1;
    vector<PipelineComponent<int>> pipelineComponents = buildBasicPipeline<int>();
    pipelineComponents[0].setState(state);
    for (int i = 0; i < pipelineComponents.size(); i++) {
        int currentState = pipelineComponents[i].getState();
        if (currentState != state) {
            return false;
        }
        if (i != pipelineComponents.size() - 1) {
            pipelineComponents[i].releaseState();
        }
    }
    return true;
}



int main() {
    baseAssemblyTest<int>();
    basicFlowTest();





    return 0;
}