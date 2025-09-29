//
// Created by teddy on 21/09/2025.
//

#ifndef CONCRETEVALIDATORLISTENER_H
#define CONCRETEVALIDATORLISTENER_H
#include "ValidatorListener.h"
#include "../../PipelineComponents/Validators/Validator.h"
#include "../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    template <typename T, typename obj>
    class ConcreteValidatorListener : public ValidatorListener<obj> {
        private:
            ValidatorStatusMessage<obj> message;
            Validator<T, obj> validator;
        public:
            void receiveMessage(ValidatorStatusMessage<obj>& message) override;
            void setPub(Validator<T, obj> pub);
        protected:
            void clearMessage() override;
            ValidatorStatusMessage<obj> passMessage() override;
    };
}

#include "ConcreteValidatorListener.tpp"
#endif //CONCRETEVALIDATORLISTENER_H
