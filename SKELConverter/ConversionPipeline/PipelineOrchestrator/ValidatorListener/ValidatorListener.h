//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATORLISTENER_H
#define VALIDATORLISTENER_H
#include "../../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    template<typename obj>
    class ValidatorListener {
    public:
        virtual void receiveMessage(ValidatorStatusMessage<obj>& message);
    protected:
        virtual void clearMessage();
        virtual ValidatorStatusMessage<obj> passMessage();
    };
} // ConversionPipeline

#endif //VALIDATORLISTENER_H
