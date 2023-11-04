/**
 * @file plastic_coverstock_good_test_01.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test is designed to validate the implementation of the member
 * function compute_oil_absorption_rate()
 *
 * ___NOTE___
 *  This will also serve as a test for the coverstock class member
 * function set_grit()
 *
 */

#include "plastic.hpp"

int main(int argc, char const* argv[]) {
  plastic* plastic_cover = new plastic("House", 10, 1000);
  plastic_cover->print();
  cout << endl;

  // Polishing to a finer grain
  plastic_cover->set_grit(2000);
  plastic_cover->print();
  cout << endl;

  // Sanding to a lower grain
  plastic_cover->set_grit(500);
  plastic_cover->print();
  cout << endl;

  // unlike the prior 2, There should be no output from this call
  plastic_cover->set_grit(500);
  return 0;
}
