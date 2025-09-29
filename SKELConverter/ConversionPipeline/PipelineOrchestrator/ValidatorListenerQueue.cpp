//
// Created by teddy on 21/09/2025.
//

#include "ValidatorListenerQueue.h"
#include "../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    template<typename T, typename obj>
    void ValidatorListenerQueue<T, obj>::addListener(ConcreteValidatorListener<Message,T> listener) {
        this.Listeners.push_back(listener);
    }
    template<typename Message, typename T, typename obj>
    void ValidatorListenerQueue< T, obj>::removeListener(ConcreteValidatorListener<Message, T> listener) {
        auto iterator = this.Listeners.begin();
        for (ConcreteValidatorListener<Message, T> item : this->Listeners) {
            ++iterator;
            if (item == listener) {
                break;
            }
        }
        this->Listeners.erase(iterator);
    }
    template<typename Message, typename T, typename obj>
    bool ValidatorListenerQueue<Message, T, obj>::confirmReceipt(Message message) {
        for (ConcreteValidatorListener<Message, T> listener : this->Listeners) {
            if (listener.passMessage() == message) {
                return true;
            }
        }
        return false;
    }
    template<typename Message, typename T, typename obj>
    ValidatorStatusMessage<obj> ValidatorListenerQueue<Message, T, obj>::getMessage() {
        ConcreteValidatorListener<Message, T> currentListener = this->Listeners.pop_front();
        ValidatorStatusMessage<obj> message = currentListener.passMessage();
        this->Listeners.push_back(currentListener);
        return message;
    }

}
