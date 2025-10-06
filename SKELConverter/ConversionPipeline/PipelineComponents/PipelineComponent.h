//
// Created by teddy on 21/09/2025.
//

#ifndef PIPELINECOMPONENT_H
#define PIPELINECOMPONENT_H


namespace ConversionPipeline {
    template <typename T>
    class PipelineComponent {
        T state;
        public:
        bool sealed;
        void joinOutput(PipelineComponent* output);
        void flush();
        void releaseState();
        void setState(T state);
        T getState();
        PipelineComponent* output;
    };
};



#endif //PIPELINECOMPONENT_H
