//
// Created by teddy on 21/09/2025.
//

#include "Validator.h"
#include "../../../ConversionPipeline/PipelineOrchestrator/ValidatorListener/ConcreteValidatorListener.h"
#include "../../Message/ValidatorStatusMessage.h"
namespace ConversionPipeline {
    template<typename T, typename obj>
    void Validator<T, obj>::notifyListener(ValidatorStatusMessage<obj> message) {
        this->listener.receiveMessage(message);
    }
    template<typename T, typename obj>
    void Validator<T, obj>::setListener(ConcreteValidatorListener<T, obj> listener) {
       this->listener = listener;
        this->listener.setPub(this);
    }


} // ConversionPipeline