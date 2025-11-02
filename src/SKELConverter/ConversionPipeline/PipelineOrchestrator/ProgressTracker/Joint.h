//
// Created by teddy on 22/09/2025.
//

#ifndef JOINT_H
#define JOINT_H
#include <string>
#include <map>
namespace ConversionPipeline {
    struct Joint {
        std::string Parent;
        std::string Child;
        std::string Type;
        std::map<std::string, float> RangeOfMotion;
    };
}
#endif //JOINT_H
