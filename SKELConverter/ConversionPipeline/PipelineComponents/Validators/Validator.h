//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "../PipelineComponent.h"
#include "../../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    template<typename T,typename obj>
    class ConcreteValidatorListener;
    template<typename T, typename obj>
    class Validator : public PipelineComponent<T> {
        ConcreteValidatorListener<T, obj> listener;
        void notifyListener(ValidatorStatusMessage<obj> message);
    public:
        Validator();
        void setListener(ConcreteValidatorListener<T, obj> listener);
        bool validate(obj object);
    };


} // ConversionPipeline

#endif //VALIDATOR_H
