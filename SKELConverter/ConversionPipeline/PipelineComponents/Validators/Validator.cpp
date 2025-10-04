//
// Created by teddy on 21/09/2025.
//

#include "Validator.h"
#include "../../../ConversionPipeline/PipelineOrchestrator/ValidatorListener/ConcreteValidatorListener.h"
namespace ConversionPipeline {
    template<typename Message, typename T>
    void Validator<T,Message>::notifyListener(Message message) {
        this->listener.receiveMessage(message);
    }
    template<typename Message, typename T>
    void Validator<Message, T>::setListener(ConcreteValidatorListener<Message, T> listener) {
       this->listener = listener;
        this->listener.setPub(this);
    }


} // ConversionPipeline