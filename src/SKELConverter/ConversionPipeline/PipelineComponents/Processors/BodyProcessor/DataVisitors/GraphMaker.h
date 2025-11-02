//
// Created by teddy on 01/10/2025.
//

#ifndef GRAPHMAKER_H
#define GRAPHMAKER_H
#include "DataVisitor.h"


namespace ConversionPipeline {
    template <typename target>

    class GraphMaker : DataVisitor<target> {
    };

} // ConversionPipeline

#endif //GRAPHMAKER_H
