//
// Created by teddy on 01/10/2025.
//

#ifndef BODYPROCESSOR_H
#define BODYPROCESSOR_H
#include <vector>
#include <map>
#include "BoundingBox/BoundingBox.h"
#include "../Processor.h"
#include "../../../Message/Message.h"
#include "Parsers/BlockerParser.h"
#include "Parsers/HeaderParser.h"

using std::vector;
using std::map;
using std::string;

namespace ConversionPipeline {
    template<typename T, typename obj>
    class BodyProcessor: Processor<T> {
        HeaderParser headerParser;
        BlockerParser blockerParser;
        BoundingBox boundingBox;



        void delegate(vector<vector<vector<int>>> rawData, BodyProcessor delegatee);
        map<string, vector<int>> findModelCuboid(obj file);
        void getBoundingBox(map<string, vector<int>> rawData);
        map<string, vector<int>> scaleBB(map<string, vector<int>> boundingBox);

    public:
        Message<obj> processOBJ(obj file);

        BodyProcessor();
    };
}


#endif //BODYPROCESSOR_H
