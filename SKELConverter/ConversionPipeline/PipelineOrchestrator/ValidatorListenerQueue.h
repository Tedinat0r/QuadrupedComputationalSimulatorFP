//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATORLISTENERQUEUE_H
#define VALIDATORLISTENERQUEUE_H

#include "ValidatorListener/ConcreteValidatorListener.h"
#include <list>

namespace ConversionPipeline {
template<typename Message>
class ValidatorListenerQueue {
private:
    std::list<ConcreteValidatorListener<Message>> Listeners;
public:
    void addListener(ConcreteValidatorListener<Message> listener);
    void removeListener(ConcreteValidatorListener<Message> listener);
    bool confirmReceipt(Message message);
    Message getMessage();
    void dequeueMessage();


};

} // ConversionPipeline

#endif //VALIDATORLISTENERQUEUE_H
