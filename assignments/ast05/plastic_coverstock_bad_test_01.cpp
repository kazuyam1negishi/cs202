/**
 * @file plastic_coverstock_bad_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test is designed to validate the implementation of the member
 * function set_grit() in coverstock_type.hpp and is designed to fail.
 *
 */

#include "plastic.hpp"

int main(int argc, char const* argv[]) {
  plastic* plastic_cover = new plastic("House", 10, 1000);
  plastic_cover->print();
  cout << endl;

  plastic_cover->set_grit(5000);
  return 0;
}
