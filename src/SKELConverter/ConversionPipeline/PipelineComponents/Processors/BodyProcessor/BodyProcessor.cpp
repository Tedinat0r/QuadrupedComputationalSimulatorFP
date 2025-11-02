//
// Created by teddy on 01/10/2025.
//

#include "BodyProcessor.h"
#include "BoundingBox/BoundingBox.h"
#include <ranges>
#include <algorithm>
#include <memory>
#include <span>
#include <set>
using std::span;
using std::greater;
using std::set;

namespace  ConversionPipeline {
    template<typename T, typename obj>
    BodyProcessor<T, obj>::BodyProcessor() {
        this->boundingBox = nullptr;
        this->headerParser = nullptr;
        this->blockerParser = nullptr;
        this->boundingBox = nullptr;
        this->sortedVertices = nullptr;
    }

    template<typename T, typename obj>
    BoundingBox BodyProcessor<T, obj>::scaleBB(vector<vector<float>> objData) {


    }
    template<typename T, typename obj>
    void BodyProcessor<T, obj>::sortVertices(vector<vector<float> > objData) {
        vector<vector<float>> z = objData;
        vector<vector<float>> y = objData;
        vector<vector<float>> x = objData;
        std::ranges::sort(z,greater{},[](const auto& row){return row[2];});
        std::ranges::sort(y,greater{},[](const auto& row){return row[1];});
        std::ranges::sort(z,greater{},[](const auto& row){return row[0];});

        this->sortedVertices = std::make_unique<SortedVertices>(SortedVertices  { z, y, x});
    }

    template<typename T, typename obj>
    void BodyProcessor<T, obj>::getBoundingBox(vector<vector<float> > rawData) {
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
        vector<vector<float>> zSorted = std::ranges::sort(rawData,greater{},[](const auto& row){return row[2];});
        vector<vector<float>> ySorted = std::ranges::sort(rawData,greater{},[](const auto& row){return row[1];});
        vector<vector<float>> xSorted = std::ranges::sort(rawData,greater{},[](const auto& row){return row[0];});
        float topFaceZ = zSorted.front()[2];
        float bottomFaceZ = zSorted.back()[2];
        float yMax = ySorted.front()[1];
        float yMin = ySorted.back()[1];
        float xMax = xSorted.front()[0];
        float xMin = xSorted.back()[0];

        /*Finding cuboid origin*/
        float zOrigin = (topFaceZ + bottomFaceZ) / 2;
        float yOrigin = (yMax + yMin) / 2;
        float xOrigin = (xMax + xMin) / 2;
        vector<float> origin = { xOrigin, yOrigin, zOrigin };

        /*Top vertices*/
        vector<float> topCornerXMinYMax = {xMin, yMax, topFaceZ};
        vector<float> topCornerXMaxYMax = {xMax, yMax, topFaceZ};
        vector<float> topCornerXMinYMin = {xMin, yMin, topFaceZ};
        vector<float> topCornerXMaxYMin = {xMax, yMin, topFaceZ};

        /*Bottom Vertices*/
        vector<float> bottomCornerXMinYMax = {xMin, yMax, bottomFaceZ};
        vector<float> bottomCornerXMaxYMax = {xMax, yMax, bottomFaceZ};
        vector<float> bottomCornerXMinYMin = {xMin, yMin, bottomFaceZ};
        vector<float> bottomCornerXMaxYMin = {xMax, yMin, bottomFaceZ};

        /*Translating cuboid if the origin is not (0,0,0)*/
        vector<vector<float>> translatedData = rawData;
        for (int i = 0; i < origin.size(); i++) {
            if(origin[i] != 0){
                float translationValue = 0 - origin[i];
                for (auto& row : translatedData ) {
                    row[i] -= translationValue;
                }
            }
        }
    }
    template<typename T, typename obj>
    vector<vector<float> > BodyProcessor<T, obj>::findTorso() {
        /*Generating approximate torso area */
        vector<vector<float>> zSorted = this->sortedVertices->ZSorted;
        vector<vector<float>> ySorted = this->sortedVertices->YSorted;
        vector<vector<float>> xSorted = this->sortedVertices->XSorted;

        float topFaceZ = zSorted.front()[2];
        float bottomFaceZ = zSorted.back()[2];
        float yMax = ySorted.front()[1];
        float minY = ySorted.back()[1];
        float xMax = xSorted.front()[0];
        float xMin = xSorted.back()[0];
        float approxBodyHeight = (topFaceZ - bottomFaceZ) * 0.22;
        float approxBodyLength = (yMax - minY) * 0.77;
        float approxBodyWidth = (xMax - xMin) * 0.38;

        /*
         *Create spans of sorted vertices, coords within the estimated ranges
         *Convert spans to sets
         *Intersection of the 3 sets will be vertices of the estimated cuboid for the torso
         *
         *
         *
         *Lower bound of torso - smallest Z + Highest Z -
         */

        auto approxBounds = [](const int axis, const float lowerBound, const float upperBound, const vector<vector<float>> &elements) {
            int maxValPos = -1;
            int minValPos = -1;
            vector<int> positions;

            int i = 0;
            while (maxValPos == -1 || minValPos == -1) {
                if (elements[i][axis] <= upperBound && maxValPos == -1) {
                    maxValPos = i;
                }
                if (i > maxValPos && elements[i][axis] > lowerBound) {
                    if (i + 1 == elements.size()) {
                        minValPos = i;
                    }else if (elements[i + 1][axis] <= lowerBound) {
                        minValPos = i;
                    }
                }
                i++;
                if (i == elements.size()) {
                    minValPos = i - 1;
                }
            }
            positions.assign({maxValPos, minValPos});
            return positions;
        };
        vector<vector<float>> test = {{0.5, 0.4, 7.8}, {0.5, 0.4, 7.2}, {0.5, 0.4, 7.1}};

        vector<int> vounds = approxBounds(2, 7.3, 7.9, test);

        float zLowerBound = topFaceZ - approxBodyHeight;
        vector<int> approxZPos = approxBounds(2, zLowerBound, approxBodyHeight, zSorted);
        vector<vector<float>> approxZVertices = {zSorted[approxZPos[0]], zSorted[approxZPos[1]]};

        float yLowerBound = yMax - approxBodyLength;
        vector<int> approxYPos = approxBounds(1, yLowerBound, approxBodyLength, ySorted);
        vector<vector<float>> approxYVertices = {ySorted[approxYPos[0]], ySorted[approxYPos[1]]};

        float xLowerBound = xMax - approxBodyWidth;
        vector<int> approxXPos = approxBounds(0, xLowerBound, approxBodyWidth, xSorted);
        vector<vector<float>> approxXVertices = {xSorted[approxXPos[0]], xSorted[approxXPos[1]]};

        vector<float> topFL = {
            approxXVertices.back()[0],
            approxYVertices.front()[1],
            approxZVertices.front()[2]
        };
        vector<float> bottomFL = {
            approxXVertices.back()[0],
            approxYVertices.front()[1],
            approxZVertices.back()[2]
        };
        vector<float> bottomFR = {
            approxXVertices.front()[0],
            approxYVertices.front()[1],
            approxZVertices.back()[2]
        };
        vector<float> topBL = {
            approxXVertices.back()[0],
            approxYVertices.back()[1],
            approxZVertices.front()[2]
        };
        vector<float> topBR = {
            approxXVertices.front()[0],
            approxYVertices.back()[1],
           approxZVertices.front()[2]
        };
        vector<float> bottomBL = {
            approxXVertices.back()[0],
            approxYVertices.back()[1],
            approxZVertices.back()[2]
        };
        vector<float> bottomBR = {
            approxXVertices.front()[0],
            approxYVertices.back()[1],
            approxZVertices.back()[2]
        };
        vector<float> topFR = {
            approxXVertices.front()[0],
            approxYVertices.front()[1],
            approxZVertices.front()[2]
        };

        return {{1.0}};
    }
    template<typename T, typename obj>
    vector<vector<float>> BodyProcessor<T, obj>::findThigh(vector<vector<float> > objData) {
    /*
     *Use proportions to get estimated position of L front thigh
     * Sort by Z descending
     * If we presume that the face of the cuboid closest to the body, then we can create a slope of the dX
     * We can derive the slope for each point, average the slope values thus far
     */
        vector<vector<float>> zSorted = this->sortedVertices.ZSorted;
        vector<vector<float>> xSorted = this->sortedVertices.XSorted;
        vector<vector<float>> ySorted = this->sortedVertices.YSorted;

        float xMax = xSorted.front()[0];
        float xMin = xSorted.back()[0];
        float yMax = ySorted.front()[1];
        float minY = ySorted.back()[1];

        int innerThighX = [xSorted, xMax]() {
            float xBound = xMax * 0.254;
            for (int i = xSorted.size() - 1; i > -1 ; i--) {
                if (xSorted[i][0] >= xBound ) {
                   return i;
                }
            }
        };
        float thighMinX = span(xSorted.begin(), xSorted.begin() + innerThighX).back()[0];

        /*
         *Y Range is unknown, so to create an estimate we can assume that the top face of the cuboid will be an equilateral
         *Doing so means that we can treat each slice as such, and filter out Y values within each slice that have a greater difference that than the X values delta
         *Then sort by X, compare delta between front and back, record and calculate average
         */

        vector<int> sliceIndices;
        for (int i = 0 ; i < zSorted.size(); i++) {
            if (i != 0) {
                if (zSorted[i][2] > zSorted[i-1][2]) {
                    sliceIndices.push_back(i);
                }
            }
        }

        float xDeltaAv = 0;
        vector<float> deltas = {};
        vector<vector<float>> thighVertexData = {};

        for (int i = 0; i < sliceIndices.size(); i++) {
            if (i + 1 < sliceIndices.size()) {
                vector<vector<float>> slice = std::ranges::copy_if(
                    std::span(
                    zSorted.begin(), zSorted.begin() + sliceIndices[i + 1]),
                        [xMax, thighMinX](auto x){ return thighMinX < x[0] > xMax && x[1] > 0;}
                    );
                float xDelta = slice.back()[0] - slice.front()[0];
                std::sort(slice.begin(), slice.end(), [](auto x, auto y){return x[1] > y[1]; });

                int j = slice.size() - 1;
                for (int k = 0; k < j; k++) {
                    if (slice[k][1] - slice[j][1] > xDelta) {
                        slice.erase(slice.begin() + j);
                    }
                    --j;
                }
                std::sort(slice.begin(), slice.end(), [](auto x, auto y){return x[0] > y[0]; });

                if (i == 0) {
                    vector<float> topfLCorner;
                    vector<float> topfRCorner;
                    vector<float> topbLCorner;
                    vector<float> topbRCorner;

                    vector<vector<float>> lVertices = slice | std::views::filter([slice] (auto x){return x[0] == slice.front()[0];});
                    vector<vector<float>> rVertices = slice | std::views::filter([slice] (auto x){return x[0] == slice.back()[0];});

                    std::sort(lVertices.begin(), lVertices.end());
                    std::sort(rVertices.begin(), rVertices.end());

                    topfLCorner = lVertices.front();
                    topfRCorner = lVertices.back();
                    topbLCorner = rVertices.front();
                    topbRCorner = rVertices.back();

                    thighVertexData.push_back(topfLCorner);
                    thighVertexData.push_back(topfRCorner);
                    thighVertexData.push_back(topbLCorner);
                    thighVertexData.push_back(topbRCorner);
                }

                float sliceXDelta = slice.front()[0] - slice.back()[0] ;
                if ( (xDeltaAv * 0.8) > sliceXDelta ) {
                    vector<float> fLCorner;
                    vector<float> fRCorner;
                    vector<float> bLCorner;
                    vector<float> bRCorner;

                    vector<vector<float>> lVertices = slice | std::views::filter([slice] (auto x){return x[0] == slice.front()[0];});
                    vector<vector<float>> rVertices = slice | std::views::filter([slice] (auto x){return x[0] == slice.back()[0];});

                    std::sort(lVertices.begin(), lVertices.end());
                    std::sort(rVertices.begin(), rVertices.end());

                    fLCorner = lVertices.front();
                    fRCorner = lVertices.back();
                    bLCorner = rVertices.front();
                    bRCorner = rVertices.back();

                    thighVertexData.push_back(fLCorner);
                    thighVertexData.push_back(fRCorner);
                    thighVertexData.push_back(bLCorner);
                    thighVertexData.push_back(bRCorner);
                }


                deltas.push_back(sliceXDelta);
                float sum = 0;
                for (float delt : deltas) {
                    sum += delt;
                }
                xDeltaAv = sum;

            }
        }
        return thighVertexData;
    }
    template<typename T, typename obj>
    vector<vector<float>> BodyProcessor<T, obj>::findLowerLeg(vector<vector<float> > objData) {

    }



}