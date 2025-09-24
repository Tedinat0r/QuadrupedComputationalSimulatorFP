//
// Created by teddy on 23/09/2025.
//

#include "ValidatorStatusMessage.h"
#include <string>
namespace ConversionPipeline {
    template<typename obj>
    ValidatorStatusMessage<obj>::ValidatorStatusMessage():Message<obj>(){
        std::string metaKeys[3] ={
        "trackerID",
            "process",
            "affectedBody"
        };
        for (int i = 0; i < 3; i++) {
            this->metadata.insert({metaKeys[i], ""});
        }
    }

}