//
// Created by teddy on 01/10/2025.
//

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include <vector>
using std::vector;
namespace ConversionPipeline {
    struct BoundingBox {
        vector<vector<int>> TopFace;
        vector<vector<int>> BottomFace;
        vector<vector<int>> LeftFace;
        vector<vector<int>> RightFace;
        vector<vector<int>> FrontFace;
        vector<vector<int>> BackFace;
    };

}
#endif //BOUNDINGBOX_H
