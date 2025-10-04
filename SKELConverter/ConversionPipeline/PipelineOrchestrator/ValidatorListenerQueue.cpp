//
// Created by teddy on 21/09/2025.
//

#include "ValidatorListenerQueue.h"
#include "../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    template<typename T, typename obj>
    void ValidatorListenerQueue<T, obj>::addListener(ConcreteValidatorListener<ValidatorStatusMessage<obj>, T> listener) {
        this.Listeners.push_back(listener);
    }
    template<typename T, typename obj>
    void ValidatorListenerQueue<T, obj>::removeListener(ConcreteValidatorListener<ValidatorStatusMessage<obj>, T> listener) {
        auto iterator = this.Listeners.begin();
        for (ConcreteValidatorListener<ValidatorStatusMessage<obj>, T> item : this->Listeners) {
            ++iterator;
            if (item == listener) {
                break;
            }
        }
        this->Listeners.erase(iterator);
    }
    template<typename T, typename obj>
    bool ValidatorListenerQueue<T, obj>::confirmReceipt(ValidatorStatusMessage<obj> message) {
        for (ConcreteValidatorListener<ValidatorStatusMessage<obj>, T> listener : this->Listeners) {
            if (listener.passMessage() == message) {
                return true;
            }
        }
        return false;
    }
    template<typename T, typename obj>
    ValidatorStatusMessage<obj> ValidatorListenerQueue<T, obj>::getMessage() {
        ConcreteValidatorListener<ValidatorStatusMessage<obj>, T> currentListener = this->Listeners.pop_front();
        ValidatorStatusMessage<obj> message = currentListener.passMessage();
        this->Listeners.push_back(currentListener);
        return message;
    }

}
