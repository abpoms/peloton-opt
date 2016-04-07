//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// operator_node.cpp
//
// Identification: src/backend/optimizer/operator_node.cpp
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "backend/optimizer/operator_node.h"

namespace peloton {
namespace optimizer {

//===--------------------------------------------------------------------===//
// Operator Node
//===--------------------------------------------------------------------===//

Operator::Operator() : node(nullptr) {}

Operator::Operator(BaseOperatorNode* node) : node(node) {}

void Operator::accept(OperatorVisitor *v) const {
  node->accept(v);
}

bool Operator::defined() const {
  return node != nullptr;
}

template <typename T> const T *Operator::as() const {
  if (node && typeid(*node) == typeid(T)) {
    return (const T *)node;
  }
  return nullptr;
}

} /* namespace optimizer */
} /* namespace peloton */
