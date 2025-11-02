//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATORLISTENERQUEUE_H
#define VALIDATORLISTENERQUEUE_H

#include "ValidatorListener/ConcreteValidatorListener.h"
#include <list>
#include "../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    class ConcreteValidatorListener;
    class ValidatorListenerQueue {
    public:
        void addListener(ConcreteValidatorListener listener);
        void removeListener(ConcreteValidatorListener listener);
        bool confirmReceipt(Message message);
        Message* getMessage();
        std::list<ConcreteValidatorListener> Listeners;


    };

} // ConversionPipeline

#endif //VALIDATORLISTENERQUEUE_H
