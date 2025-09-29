//
// Created by teddy on 21/09/2025.
//

#include "ConcreteValidatorListener.h"
#include "../../Message/ValidatorStatusMessage.h"

#include <stddef.h>


namespace ConversionPipeline {
    template <typename T, typename obj>
    void ConcreteValidatorListener<T, obj>::receiveMessage(ValidatorStatusMessage<obj>& message){
        this->message = message;
    }
    template <typename T, typename obj>
    ValidatorStatusMessage<obj> ConcreteValidatorListener<T, obj>::passMessage(){
        this->validator.releaseState();
        return this->message;
    }
    template <typename T, typename obj>
    void ConcreteValidatorListener<T, obj>::clearMessage() {
        this->message = nullptr;
    }
};


