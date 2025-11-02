//
// Created by teddy on 21/09/2025.
//

#ifndef CONCRETEVALIDATORLISTENER_H
#define CONCRETEVALIDATORLISTENER_H
#include "ValidatorListener.h"
#include "../../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    class Validator;
    class ConcreteValidatorListener : public ValidatorListener {
        public:
            Message* message = nullptr;
            Validator* validator = nullptr;
            void receiveMessage(Message* message) override;
            void setPub(Validator* pub);
            ConcreteValidatorListener() = default;
            Message* passMessage() override;
        protected:
            void clearMessage() override;
    };
}

#endif //CONCRETEVALIDATORLISTENER_H
