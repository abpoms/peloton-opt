//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// memo.cpp
//
// Identification: src/backend/optimizer/memo.cpp
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "backend/optimizer/memo.h"

#include <cassert>

namespace peloton {
namespace optimizer {

//===--------------------------------------------------------------------===//
// Memo
//===--------------------------------------------------------------------===//
Memo::Memo() {}

bool Memo::InsertExpression(std::shared_ptr<GroupExpression> gexpr) {
  return InsertExpression(gexpr, UNDEFINED_GROUP);
}

bool Memo::InsertExpression(std::shared_ptr<GroupExpression> gexpr,
                            GroupID target_group)
{
  // Lookup in hash table
  auto it = group_expressions.find(gexpr.get());

  bool new_expression;
  if (it != group_expressions.end()) {
    new_expression = false;
    assert(target_group != UNDEFINED_GROUP &&
           target_group == (*it)->GetGroupID());
  } else {
    new_expression = true;
    group_expressions.insert(gexpr.get());
    // New expression, so try to insert into an existing group or
    // create a new group if none specified
    GroupID group_id;
    if (target_group == UNDEFINED_GROUP) {
      group_id = AddNewGroup();
    } else {
      group_id = target_group;
    }
    Group *group = GetGroupByID(group_id);
    group->AddExpression(gexpr);
  }

  return new_expression;
}

const std::vector<Group> &Memo::Groups() const {
  return groups;
}

Group *Memo::GetGroupByID(GroupID id) {
  return &(groups[id]);
}

GroupID Memo::AddNewGroup() {
  GroupID new_group_id = groups.size();
  groups.emplace_back(new_group_id);
  return new_group_id;
}

} /* namespace optimizer */
} /* namespace peloton */
