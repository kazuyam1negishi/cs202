/**
 * @file performance_bad_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test is designed to fail at compile time.
 *
 * The performance class should not be able to be instantiated
 *
 */

#include "performance.hpp"

int main(int argc, char const* argv[]) {
  performance* performance_cover =
      new performance("HK22", 2, 500, density::medium);

  // print() should remain unimplemented from coverstock_type
  performance->print();  
  return 0;
}
