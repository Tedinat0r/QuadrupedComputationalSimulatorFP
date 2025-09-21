//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATORLISTENER_H
#define VALIDATORLISTENER_H

namespace ConversionPipeline {
    template <typename Message>
    class ValidatorListener {
    public:
        virtual void receiveMessage(Message& message);
    protected:
        virtual void clearMessage();
        virtual Message passMessage();
    };
} // ConversionPipeline

#endif //VALIDATORLISTENER_H
