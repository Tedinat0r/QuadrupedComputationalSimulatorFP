//
// Created by teddy on 21/09/2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "../PipelineComponent.h"
#include "../../Message/ValidatorStatusMessage.h"
#include "vector"
using std::vector;

namespace ConversionPipeline {
    class ConcreteValidatorListener;
    class Validator : public PipelineComponent {
        ConcreteValidatorListener* listener;

    public:
        Validator() = default;
        void setListener(ConcreteValidatorListener* listener);
        void notifyListener(Message* message);
        bool validate(vector<vector<float>> object);
    };


} // ConversionPipeline

#endif //VALIDATOR_H
