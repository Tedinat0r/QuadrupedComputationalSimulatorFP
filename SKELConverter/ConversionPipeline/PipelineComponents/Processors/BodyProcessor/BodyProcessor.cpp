//
// Created by teddy on 01/10/2025.
//

#include "BodyProcessor.h"




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
    map<string, vector<int> > BodyProcessor<T, obj>::scaleBB(map<string, vector<int> > boundingBox) {
        
    }

}