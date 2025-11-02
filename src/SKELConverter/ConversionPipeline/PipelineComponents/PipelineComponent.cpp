//
// Created by teddy on 21/09/2025.
//

#include "PipelineComponent.h"

#include <iostream>

namespace ConversionPipeline {
    void PipelineComponent::joinOutput(PipelineComponent* output) {
        this->output = output;
    }
    void PipelineComponent::flush() {
        this->state = nullptr;
        /*Must add logic to release state to cache*/
    }
    void PipelineComponent::releaseState() {
        if (this->state != nullptr) {
            if (this->output != nullptr) {
                if (!this->output->sealed) {
                    this->output->setState(std::move(this->state));
                }
            }
        }
    }
    void PipelineComponent::setState(std::unique_ptr<Message> state) {
        this->state = std::move(state);
    }
    Message* PipelineComponent::getState() const {
        return this->state.get();
    }




}
