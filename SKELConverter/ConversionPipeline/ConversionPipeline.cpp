//
// Created by teddy on 30/09/2025.
//

#include "ConversionPipeline.h"

namespace ConversionPipeline {
    template<typename obj, typename T>
    void ConversionPipeline<obj, T>::buildPipeline() {
        for (int i = 0; i < this->components.size(); i++) {
            components[i].joinOutput(validators[i]);
            ConcreteValidatorListener< T, obj > listener = ConcreteValidatorListener<T,obj>();
            listener.setPub(validators[i]);
            /*Add listener to listener vector in orchestrator, new method to move listeners from vector to queue*/
        }
    }


} // ConversionPipeline