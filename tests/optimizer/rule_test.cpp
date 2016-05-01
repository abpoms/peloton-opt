//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// rule_test.cpp
//
// Identification: tests/optimizer/rule_test.cpp
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "harness.h"

#define private public

#include "backend/optimizer/optimizer.h"
#include "backend/optimizer/rule.h"
#include "backend/optimizer/rule_impls.h"
#include "backend/optimizer/op_expression.h"
#include "backend/optimizer/operators.h"

namespace peloton {
namespace test {

//===--------------------------------------------------------------------===//
// Binding Tests
//===--------------------------------------------------------------------===//

using namespace optimizer;

class RuleTests : public PelotonTest {};

TEST_F(RuleTests, SimpleRuleApplyTest) {
  // Build op plan node to match rule
  auto left_get = std::make_shared<OpExpression>(LogicalGet::make(0, {}));
  auto right_get = std::make_shared<OpExpression>(LogicalGet::make(1, {}));
  auto pred =
    std::make_shared<OpExpression>(ExprConstant::make(Value::GetTrue()));
  auto join = std::make_shared<OpExpression>(LogicalInnerJoin::make());
  join->PushChild(left_get);
  join->PushChild(right_get);
  join->PushChild(pred);

  // Setup rule
  InnerJoinCommutativity rule;

  EXPECT_TRUE(rule.Check(join));

  std::vector<std::shared_ptr<OpExpression>> outputs;
  rule.Transform(join, outputs);
  EXPECT_EQ(outputs.size(), 1);
}

} /* namespace test */
} /* namespace peloton */
