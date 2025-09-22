//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "../PipelineComponent.h"
#include "../../../ConversionPipeline/PipelineOrchestrator/ValidatorListener/ConcreteValidatorListener.h"
namespace ConversionPipeline {
    template<typename Message>
    class Validator : public PipelineComponent {
        ConcreteValidatorListener<Message> listener;
        void notifyListener(Message message);
    public:
        void setListener(ConcreteValidatorListener<Message> listener);
    };

} // ConversionPipeline

#endif //VALIDATOR_H
