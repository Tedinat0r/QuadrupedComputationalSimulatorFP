//
// Created by teddy on 21/09/2025.
//

#ifndef PIPELINECOMPONENT_H
#define PIPELINECOMPONENT_H
#include <memory>

#include "../Message/Message.h"

namespace ConversionPipeline {
    class PipelineComponent {
        std::unique_ptr<Message> state = nullptr;
        public:
        bool sealed = false;
        void joinOutput(PipelineComponent* output);
        void flush();
        void releaseState();
        void setState(std::unique_ptr<Message> state);
        Message* getState() const;
        PipelineComponent* output;
        PipelineComponent() = default;
    };
};



#endif //PIPELINECOMPONENT_H
