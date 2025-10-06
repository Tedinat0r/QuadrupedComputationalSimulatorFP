//
// Created by teddy on 01/10/2025.
//

#ifndef DATAVISITOR_H
#define DATAVISITOR_H

namespace ConversionPipeline {
    template <typename Target>
class DataVisitor {

    virtual void visit(Target target);
};

} // ConversionPipeline

#endif //DATAVISITOR_H
