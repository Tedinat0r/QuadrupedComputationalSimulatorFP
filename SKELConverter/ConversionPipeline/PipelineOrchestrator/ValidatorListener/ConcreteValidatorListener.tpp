//
// Created by teddy on 21/09/2025.
//

#include "ConcreteValidatorListener.h"

#include <stddef.h>


namespace ConversionPipeline {
    template <typename Message, typename T>
    void ConcreteValidatorListener<Message, T>::receiveMessage(Message& message){
        this->message = message;
    }
    template <typename Message, typename T>
    Message ConcreteValidatorListener<Message, T>::passMessage(){
        this->validator.releaseState();
        return this->message;
    }
    template <typename Message, typename T>
    void ConcreteValidatorListener<Message, T>::clearMessage() {
        this->message = NULL;
    }
};


