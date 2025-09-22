//
// Created by teddy on 21/09/2025.
//

#ifndef PIPELINECOMPONENT_H
#define PIPELINECOMPONENT_H


namespace ConversionPipeline {
    template <typename T>
    class PipelineComponent {
    PipelineComponent output;
    T state;
        public:
        bool sealed;
        PipelineComponent();
        void joinOutput(PipelineComponent output);
        void flush();
        void releaseState();
    };
};



#endif //PIPELINECOMPONENT_H
