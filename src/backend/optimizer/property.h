//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// property.h
//
// Identification: src/backend/optimizer/property.h
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include "backend/optimizer/util.h"

namespace peloton {
namespace optimizer {

enum class PropertyType {
  Sort,
  Columns,
};

class Property {
 public:
  virtual hash_t Hash() const = 0;

  virtual bool operator==(const Property &r) const = 0;

};

} /* namespace optimizer */
} /* namespace peloton */
