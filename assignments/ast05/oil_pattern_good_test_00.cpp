/**
 * @file oil_pattern_good_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test is designed to test the validity of the oil_pattern class
 * member functions:
 *
 * constructor, layout_to_string(), copy_oil_volume_segments(), and
 * destructor
 *
 */

#include <iostream>
using std::cout, std::endl, std::string;

#include "oil_pattern.hpp"

int main(int argc, char const* argv[]) {
  oil_pattern* pattern = new oil_pattern(layout_ids::cheetah);
  pattern->print();
  cout << endl;
  delete pattern;

  pattern = new oil_pattern(layout_ids::scorpion);
  pattern->print();
  cout << endl;
  delete pattern;

  pattern = new oil_pattern(layout_ids::shark);
  pattern->print();
  cout << endl;
  delete pattern;

  return 0;
}
