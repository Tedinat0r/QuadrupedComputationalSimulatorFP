//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATORLISTENERQUEUE_H
#define VALIDATORLISTENERQUEUE_H

#include "ValidatorListener/ConcreteValidatorListener.h"
#include <list>
#include "../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    template<typename T, typename obj>
    class ValidatorListenerQueue {
    private:
        std::list<ConcreteValidatorListener<ValidatorStatusMessage<obj>, T>> Listeners;
    public:
        void addListener(ConcreteValidatorListener<ValidatorStatusMessage<obj>, T> listener);
        void removeListener(ConcreteValidatorListener<ValidatorStatusMessage<obj>, T> listener);
        bool confirmReceipt(ValidatorStatusMessage<obj> message);
        ValidatorStatusMessage<obj> getMessage();


    };

} // ConversionPipeline

#endif //VALIDATORLISTENERQUEUE_H
