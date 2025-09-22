//
// Created by teddy on 21/09/2025.
//

#include "Validator.h"

namespace ConversionPipeline {
    template<typename Message>
    void Validator<Message>::notifyListener(Message message) {
        this->listener.receiveMessage(message);
    }

} // ConversionPipeline