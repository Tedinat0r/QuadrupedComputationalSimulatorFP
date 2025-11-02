//
// Created by teddy on 30/09/2025.
//

#include "CPipeline.h"

namespace ConversionPipeline {
    void CPipeline::buildPipeline() {
        for (int i = 0; i < this->components.size(); i++) {
            Validator validator = std::move(validators[i]);
            Validator* validatorPtr = &validator;
            components[i].joinOutput(validatorPtr);
            ConcreteValidatorListener listener = ConcreteValidatorListener();
            listener.setPub(validatorPtr);
            /*Add listener to listener vector in orchestrator, new method to move listeners from vector to queue*/
        }
    }


} // ConversionPipeline