//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// stats.h
//
// Identification: src/backend/optimizer/stats.h
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include "backend/optimizer/tuple_sample.h"

namespace peloton {
namespace optimizer {

//===--------------------------------------------------------------------===//
// Stats
//===--------------------------------------------------------------------===//
class Stats {
 public:
  Stats(TupleSample *sample);

 private:
  TupleSample *sample;
};

} /* namespace optimizer */
} /* namespace peloton */
