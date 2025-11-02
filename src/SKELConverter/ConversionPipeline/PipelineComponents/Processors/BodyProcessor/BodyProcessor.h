//
// Created by teddy on 01/10/2025.
//

#ifndef BODYPROCESSOR_H
#define BODYPROCESSOR_H
#include <vector>
#include <map>
#include <memory>

#include "BoundingBox/BoundingBox.h"
#include "../Processor.h"
#include "../../../Message/Message.h"
#include "Parsers/BlockerParser.h"
#include "Parsers/HeaderParser.h"
#include "BoundingBox/BoundingBox.h"

using std::vector;
using std::map;
using std::string;

namespace ConversionPipeline {
    template<typename T, typename obj>
    class BodyProcessor: Processor<T> {
        HeaderParser* headerParser;
        BlockerParser* blockerParser;
        BoundingBox* boundingBox;
        struct SortedVertices {
            vector<vector<float>> ZSorted;
            vector<vector<float>> XSorted;
            vector<vector<float>> YSorted;
        };
        std::unique_ptr<SortedVertices> sortedVertices;

        void delegate(vector<vector<vector<int>>> rawData, BodyProcessor delegatee);
        map<string, vector<int>> findModelCuboid(obj file);
        void getBoundingBox(vector<vector<float>> rawData);
        BoundingBox scaleBB(vector<vector<float>> objData);
    public:

        Message processOBJ(obj file);
        vector<vector<float>> findTorso();
        vector<vector<float>> findThigh(vector<vector<float>> objData);
        vector<vector<float>> findLowerLeg(vector<vector<float>> objData);
        void sortVertices(vector<vector<float>> objData);

        BodyProcessor();
    };
}


#endif //BODYPROCESSOR_H
