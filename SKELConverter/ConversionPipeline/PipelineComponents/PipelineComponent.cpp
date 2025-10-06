//
// Created by teddy on 21/09/2025.
//

#include "PipelineComponent.h"
namespace ConversionPipeline {
    template<typename T>
    void PipelineComponent<T>::joinOutput(PipelineComponent* output) {
        this->output = output;
    }
    template<typename T>
    void PipelineComponent<T>::flush() {
        this->state = nullptr;
        /*Must add logic to release state to cache*/
    }
    template<typename T>
    void PipelineComponent<T>::releaseState() {
        if (this->state != nullptr) {
            if (this->output != nullptr) {
                if (!this->output->sealed) {
                    this->output->state = this->state;
                    this->state = nullptr;
                }
            }
        }
    }
    template<typename T>
    void PipelineComponent<T>::setState(T state) {
        this->state = state;
    }
    template<typename T>
    T PipelineComponent<T>::getState() {
        return this->state;
    }




}
