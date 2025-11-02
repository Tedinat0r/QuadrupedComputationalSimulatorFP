//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATORLISTENER_H
#define VALIDATORLISTENER_H
#include "../../Message/ValidatorStatusMessage.h"

namespace ConversionPipeline {
    class ValidatorListener {
    public:
        virtual ~ValidatorListener() = default;

        virtual void receiveMessage(Message* message) = 0;
    protected:
        virtual void clearMessage() = 0;
        virtual Message* passMessage() = 0;
    };
} // ConversionPipeline

#endif //VALIDATORLISTENER_H
