//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "../PipelineComponent.h"
#include "../../../ConversionPipeline/PipelineOrchestrator/ValidatorListener/ConcreteValidatorListener.h"
namespace ConversionPipeline {
    template<typename Message, typename T>
    class Validator : public PipelineComponent<T> {
        ConcreteValidatorListener<Message, T> listener;
        void notifyListener(Message message);
    public:
        void setListener(ConcreteValidatorListener<Message, T> listener);
        bool validate(T obj);
    };


} // ConversionPipeline

#endif //VALIDATOR_H
