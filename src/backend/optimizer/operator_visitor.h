//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// operator_visitor.h
//
// Identification: src/backend/optimizer/operator_visitor.h
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

namespace peloton {
namespace optimizer {

class Variable;
class Constant;
class AndOperator;
class OrOperator;
class NotOperator;
class Attribute;
class Table;
class Join;
class OrderBy;
class Select;

//===--------------------------------------------------------------------===//
// Operator Visitor
//===--------------------------------------------------------------------===//

class OperatorVisitor {
 public:
  virtual ~OperatorVisitor() {};

  virtual void visit(const Variable*) = 0;
  virtual void visit(const Constant*) = 0;
  virtual void visit(const AndOperator*) = 0;
  virtual void visit(const OrOperator*) = 0;
  virtual void visit(const NotOperator*) = 0;
  virtual void visit(const Attribute*) = 0;
  virtual void visit(const Table*) = 0;
  virtual void visit(const Join*) = 0;
  virtual void visit(const OrderBy*) = 0;
  virtual void visit(const Select*) = 0;
};

} /* namespace optimizer */
} /* namespace peloton */
