/**
 * @file plastic_good_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test is designed to validate the functionality of the
 * following plastic data type functions
 * plastic() and compute_oil_absorption_rate()
 *
 */

#include "plastic.hpp"

int main(int argc, char const* argv[]) {
  plastic* plastic_cover = new plastic("House", 10, 4000);
  plastic_cover->print();
  return 0;
}
