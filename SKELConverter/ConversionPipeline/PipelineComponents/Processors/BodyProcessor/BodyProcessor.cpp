//
// Created by teddy on 01/10/2025.
//

#include "BodyProcessor.h"
#include "BoundingBox/BoundingBox.h"
#include <ranges>
#include <algorithm>
#include <span>
using std::span;
using std::greater;



namespace  ConversionPipeline {
    template<typename T, typename obj>
    BodyProcessor<T, obj>::BodyProcessor() {
        this->boundingBox = BoundingBox{
            {
                {-45,100, 55},{45,100, 55}, {-45, -100, 55},  {45, -100, 55}
            },
            {
                {-45,100, -55},{45,100, -55}, {-45, -100, -55},  {45, 100, -55}
            },
            {
                {-45, 100, 55}, {-45, 100, -55}, {-45, -100, 55}, {-45, -100, -55}
            },
            {
                {45, 100, 55}, {45, 100, -55}, {45, -100, 55}, {45, -100, -55}
            },
            {
                {-45, 100, 55}, {-45, 100, -55}, {45, 100, 55}, {45, 100, -55}
            },
            {
                {-45, -100, 55}, {-45, -100, -55}, {45, -100, 55}, {45, -100, -55}
            }
        };
    };
    template<typename T, typename obj>
    BoundingBox BodyProcessor<T, obj>::scaleBB(vector<vector<int>> objData) {


    }
    template<typename T, typename obj>
    void BodyProcessor<T, obj>::getBoundingBox(vector<vector<int> > rawData) {
            /**
         *Find vertices that constitute the top face
         *Find difference between Y coords on one side, divide by two to get Y coord of origin
         *Find difference between X coords on horizontal side, divide by to get X coord of origin
         *
         *Find points for front face - search for coords where Z != Z of two bottom vertices of top face
         *Delta top face cords, new coords - 2 find Z origin
         *
         *
         *
         */

        /*Finding top face*/
        vector<vector<int>> zSorted = std::ranges::sort(rawData,greater{},[](const auto& row){return row[2];});
        vector<vector<int>> ySorted = std::ranges::sort(rawData,greater{},[](const auto& row){return row[1];});
        vector<vector<int>> xSorted = std::ranges::sort(rawData,greater{},[](const auto& row){return row[0];});
        int topFaceZ = zSorted.front()[2];
        int bottomFaceZ = zSorted.back()[2];
        int yMax = ySorted.front()[1];
        int yMin = ySorted.back()[1];
        int x max
        vector<vector<int>> topFace = {
            {xSorted.front()[0], ySorted.front()[1], topFaceZ },
            {xSorted.back()[0], ySorted.front()[1], topFaceZ },
            {xSorted.front()[0], ySorted.back()[1], topFaceZ },
            {xSorted.back()[0], ySorted.back()[1], topFaceZ }
        };
        vector<vector<int>> frontFace = {
            {xSorted.front()[0], ySorted.front()[1], topFaceZ},
            {xSorted.back()[0], ySorted.front()[1], topFaceZ},
            {xSorted.front()[0], ySorted.front()[1], bottomFaceZ},
            {xSorted.back()[0], ySorted.front()[1], bottomFaceZ},

        };
        /*Finding cuboid origin*/
        int zOrigin = (topFaceZ + bottomFaceZ) / 2;
        int yOrigin;
        for (vector<int> coords: span<vector<int>>(zSorted.begin(), zSorted.begin +
                [&]() {
                    ([zSorted](const auto &row){ if (zSorted[row][2] < zSorted[row-1][2]){ return row - 1;}});
                })){

            }
    }


}