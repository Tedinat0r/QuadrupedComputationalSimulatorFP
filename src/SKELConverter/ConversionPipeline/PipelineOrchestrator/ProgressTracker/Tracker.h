//
// Created by teddy on 22/09/2025.
//

#ifndef TRACKER_H
#define TRACKER_H
#include "Bodies.h"
#include <vector>
#include <string>
namespace ConversionPipeline {
    struct ProgressTracker {
        Bodies bodies;
        std::string ID;
        std::string processStart;
        bool blocked;
        std::vector<std::string> blocking;
    };
}
#endif //TRACKER_H
