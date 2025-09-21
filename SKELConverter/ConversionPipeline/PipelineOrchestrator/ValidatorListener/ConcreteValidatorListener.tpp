//
// Created by teddy on 21/09/2025.
//

#include "ConcreteValidatorListener.h"

#include <stddef.h>


namespace ConversionPipeline {
    template <typename Message>
    void ConcreteValidatorListener<Message>::receiveMessage(Message& message){
        this->message = message;
    }
    template <typename Message>
    Message ConcreteValidatorListener<Message>::passMessage(){
        return this->message;
    }
    template <typename Message>
    void ConcreteValidatorListener<Message>::clearMessage() {
        this->message = NULL;
    }
};


