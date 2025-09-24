//
// Created by teddy on 21/09/2025.
//

#ifndef CONCRETEVALIDATORLISTENER_H
#define CONCRETEVALIDATORLISTENER_H
#include "ValidatorListener.h"
#include "../../PipelineComponents/Validators/Validator.h"

namespace ConversionPipeline {
    template <typename Message, typename T>
    class ConcreteValidatorListener : public ValidatorListener<Message> {
        private:
            Message message;
            Validator<Message, T> validator;
        public:
            void receiveMessage(Message& message) override;
            void setPub(Validator<Message, T> pub);
        protected:
            void clearMessage() override;
            Message passMessage() override;
    };
}


#include "ConcreteValidatorListener.tpp"
#endif //CONCRETEVALIDATORLISTENER_H
