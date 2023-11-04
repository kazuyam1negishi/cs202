/**
 * @file core_type_bad_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief 
 *  This test case is designed to fail.
 *
 * core_type is an abstract class and thus cannot be instantiated
 * 
 */

#include <iostream>

#include "core_type.hpp"

int main(int argc, char const* argv[]) {
  core_type* core = new core_type("Empty", 0, 0, 0.f);
  std::cout << core->get_core_mass() << std::endl;
  return 0;
}
