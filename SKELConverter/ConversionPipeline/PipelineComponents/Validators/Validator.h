//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "../PipelineComponent.h"
#include "../../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    template<typename T,typename obj>
    class ConcreteValidatorListener<T>;
    template<typename T, typename obj>
    class Validator : public PipelineComponent<T> {
        ConcreteValidatorListener<T, obj> listener;
        void notifyListener(ValidatorStatusMessage<obj> message);
    public:
        Validator<T>();
        void setListener(ConcreteValidatorListener<T, obj> listener);
        bool validate(T obj);
    };


} // ConversionPipeline

#endif //VALIDATOR_H
