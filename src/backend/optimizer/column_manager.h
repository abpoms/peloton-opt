//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// column_manager.h
//
// Identification: src/backend/optimizer/column_manager.h
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include "backend/optimizer/column.h"

namespace peloton {
namespace optimizer {

class ColumnManager {
 public:
  ColumnManager();
  ~ColumnManager();

  Column *LookupColumn(oid_t base_table, oid_t column_index);

  Column *LookupColumnByID(ColumnID id);

  Column *AddColumn(std::string name,
                    oid_t base_table,
                    oid_t column_index,
                    ValueType type);

 private:
  ColumnID next_column_id;

  std::vector<Column *> columns;
  std::map<std::tuple<oid_t, oid_t>, Column *> table_col_index_to_column;
  std::map<ColumnID, Column *> id_to_column;
};

} /* namespace optimizer */
} /* namespace peloton */
