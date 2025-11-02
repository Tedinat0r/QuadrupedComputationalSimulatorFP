//
// Created by teddy on 22/09/2025.
//

#include "Message.h"
#include <ctime>
namespace ConversionPipeline {
    Message::Message() {
        this->creationTime = time(nullptr);
    }

} // ConversionPipeline