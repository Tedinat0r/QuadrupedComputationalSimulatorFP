//
// Created by teddy on 21/09/2025.
//

#include "Validator.h"
#include "../../../ConversionPipeline/PipelineOrchestrator/ValidatorListener/ConcreteValidatorListener.h"
#include "../../Message/ValidatorStatusMessage.h"
namespace ConversionPipeline {

    void Validator::notifyListener(Message* message) {
        this->listener->receiveMessage(message);
    }
    void Validator::setListener(ConcreteValidatorListener* listener) {
       this->listener = listener;
       this->listener->setPub(this);
    }


} // ConversionPipeline