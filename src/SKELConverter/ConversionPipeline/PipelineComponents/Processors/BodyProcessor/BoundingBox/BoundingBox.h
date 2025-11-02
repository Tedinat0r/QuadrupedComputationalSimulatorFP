//
// Created by teddy on 01/10/2025.
//

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include <vector>
using std::vector;
namespace ConversionPipeline {
    struct BoundingBox {
        vector<vector<float>> TopFace;
        vector<vector<float>> BottomFace;
        vector<vector<float>> LeftFace;
        vector<vector<float>> RightFace;
        vector<vector<float>> FrontFace;
        vector<vector<float>> BackFace;
    };

}
#endif //BOUNDINGBOX_H
