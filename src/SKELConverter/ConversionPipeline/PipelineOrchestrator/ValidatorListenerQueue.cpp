//
// Created by teddy on 21/09/2025.
//

#include "ValidatorListenerQueue.h"
#include "../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    void ValidatorListenerQueue::addListener(ConcreteValidatorListener listener) {
        this->Listeners.push_back(listener);
    }
    void ValidatorListenerQueue::removeListener(ConcreteValidatorListener listener) {
        auto iterator = this->Listeners.begin();
        for (ConcreteValidatorListener item : this->Listeners) {
            ++iterator;
            if constexpr (&item == &listener) {
                break;
            }
        }
        this->Listeners.erase(iterator);
    }
    Message* ValidatorListenerQueue::getMessage() {
        ConcreteValidatorListener currentListener = this->Listeners.front();
        this->Listeners.pop_front();
        Message* message = currentListener.passMessage();
        this->Listeners.push_back(currentListener);
        return message;
    }

}
