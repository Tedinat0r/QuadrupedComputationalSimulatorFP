//
// Created by teddy on 21/09/2025.
//

#include "ConcreteValidatorListener.h"
#include "../../Message/ValidatorStatusMessage.h"
#include "../../PipelineComponents/Validators/Validator.h"

#include <stddef.h>


namespace ConversionPipeline {
    void ConcreteValidatorListener::receiveMessage(Message* message){
        this->message = message;
    }
    Message* ConcreteValidatorListener::passMessage(){
        this->validator->releaseState();
        return this->message;
    }
    void ConcreteValidatorListener::clearMessage() {
        ValidatorStatusMessage msg = ValidatorStatusMessage();
        ValidatorStatusMessage* msgPtr = &msg;
        this->message = nullptr;
    }
    void ConcreteValidatorListener::setPub(Validator* pub) {
        this->validator = pub;
    }

};


