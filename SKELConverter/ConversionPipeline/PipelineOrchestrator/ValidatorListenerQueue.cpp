//
// Created by teddy on 21/09/2025.
//

#include "ValidatorListenerQueue.h"

namespace ConversionPipeline {
    template<typename Message>
    void ValidatorListenerQueue<Message>::addListener(ConcreteValidatorListener<Message> listener) {
        this.Listeners.push_back(listener);
    }
    template<typename Message>
    void ValidatorListenerQueue<Message>::removeListener(ConcreteValidatorListener<Message> listener) {
        auto iterator = this.Listeners.begin();
        for (ConcreteValidatorListener<Message> item : this->Listeners) {
            ++iterator;
            if (item == listener) {
                break;
            }
        }
        this->Listeners.erase(iterator);
    }
    template<typename Message>
    bool ValidatorListenerQueue<Message>::confirmReceipt(Message message) {
        for (ConcreteValidatorListener<Message> listener : this->Listeners) {
            if (listener.passMessage() == message) {
                return true;
            }
        }
        return false;
    }
    template<typename Message>
    Message ValidatorListenerQueue<Message>::getMessage() {
        ConcreteValidatorListener<Message> currentListener = this->Listeners.pop_front();
        Message message = currentListener.passMessage();
        this->Listeners.push_back(currentListener);
        return message;
    }

}
