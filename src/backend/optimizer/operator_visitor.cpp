//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// operator_visitor.cpp
//
// Identification: src/backend/optimizer/operator_visitor.cpp
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "backend/optimizer/operator_visitor.h"

namespace peloton {
namespace optimizer {

//===--------------------------------------------------------------------===//
// Operator Visitor
//===--------------------------------------------------------------------===//

void OperatorVisitor::visit(const LogicalGet*) {
}

void OperatorVisitor::visit(const LogicalProject*) {
}

void OperatorVisitor::visit(const LogicalFilter*) {
}

void OperatorVisitor::visit(const LogicalInnerJoin*) {
}

void OperatorVisitor::visit(const LogicalLeftJoin*) {
}

void OperatorVisitor::visit(const LogicalRightJoin*) {
}

void OperatorVisitor::visit(const LogicalOuterJoin*) {
}

void OperatorVisitor::visit(const LogicalAggregate*) {
}

void OperatorVisitor::visit(const LogicalLimit*) {
}

} /* namespace optimizer */
} /* namespace peloton */