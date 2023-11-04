/**
 * @file symmetric_good_test_02.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *    This test is designed to validate the functionality of the
 * compute_differential() of the symmetric data type.
 *
 * ___NOTE___
 *  This test is also related to the bowling_ball data type.
 * In this test case, we are forcing the parameters, rather than
 * relying on the parent class data members.
 *
 */

#include "symmetric.hpp"

int main(int argc, char const* argv[]) {
  symmetric_core* core = new symmetric_core("PowerCor", 1, 10, 2.5, true,
                                            symmetric_geometry::lightbulb);
  // Initial print without calculations
  core->print();
  cout << endl;

  // Standard differential value
  float drill_layout_1[3] = {4, 4, 2};
  core->compute_differential(&drill_layout_1[0]);

  core->print();
  cout << endl;

  // Maximum differential value
  float drill_layout_2[3] = {6, 4, 0};
  core->compute_differential(&drill_layout_2[0]);

  core->print();
  cout << endl;

  delete core;
  return 0;
}
