//
// Created by teddy on 21/09/2025.
//

#ifndef CONCRETEVALIDATORLISTENER_H
#define CONCRETEVALIDATORLISTENER_H
#include "ValidatorListener.h"

namespace ConversionPipeline {
    template <typename Message>
    class ConcreteValidatorListener : public ValidatorListener<Message> {
        private:
            Message message;
        public:
            void receiveMessage(Message& message) override;
        protected:
            void clearMessage() override;
            Message passMessage() override;
    };
}


#include "ConcreteValidatorListener.tpp"
#endif //CONCRETEVALIDATORLISTENER_H
