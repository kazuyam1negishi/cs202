/**
 * @file coverstock_type_bad_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test is designed to fail at compile time.
 *
 * The coverstock_type should not be able to be instantiated as a type.
 *
 * @date 2023-10-15
 */

#include "coverstock_type.hpp"

int main(int argc, char const* argv[]) {
  coverstock_type* coverstock = new coverstock_type("HK22", 2, 500);
  coverstock->print();
  return 0;
}
