//
// Created by teddy on 23/09/2025.
//

#ifndef VALIDATORSTATUSMESSAGE_H
#define VALIDATORSTATUSMESSAGE_H
#include "Message.h"

namespace ConversionPipeline {
    template <typename obj>
    class ValidatorStatusMessage: Message<obj> {
        ValidatorStatusMessage();
    };
}



#endif //VALIDATORSTATUSMESSAGE_H
