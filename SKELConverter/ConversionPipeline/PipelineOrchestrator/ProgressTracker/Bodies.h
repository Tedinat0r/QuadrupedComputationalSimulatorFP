//
// Created by teddy on 22/09/2025.
//

#ifndef BODIES_H
#define BODIES_H
#include "Joint.h"
#include <vector>

namespace ConversionPipeline {
    struct Body {
        bool isParsed;
        bool hasJoints;
        bool hasMaterials;
        bool hasMass;
        std::vector<Joint> Joints;
    };
    struct Bodies {
        Body Torso;
        Body ShoulderF;
        Body shoulderB;
        Body LegsFront;
        Body LegsBack;
    };


}
#endif //BODIES_H
