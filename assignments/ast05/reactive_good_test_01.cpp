/**
 * @file reactive_good_test_01.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *   This test is designed to validate the implementation of reative's
 * implemenations of the member functions:
 *
 * material_to_string() and compute_oil_absorption_rate()
 *
 */

#include "reactive.hpp"

int main(int argc, char const* argv[]) {
  // Test density factors
  coverstock_type* cover =
      new reactive("HK22", 2, 1500, density::hard, material::hybrid);
  cover->print();
  cout << endl;
  delete cover;

  cover = new reactive("HK22", 2, 1500, density::medium, material::hybrid);
  cover->print();
  cout << endl;
  delete cover;

  cover = new reactive("HK22", 2, 1500, density::soft, material::hybrid);
  cover->print();
  cout << endl;
  delete cover;

  // Test material factors and oil_absorption rate values
  cover = new reactive("HK22", 2, 1500, density::hard, material::hybrid);
  cover->print();
  cout << endl;
  delete cover;

  cover = new reactive("HK22", 2, 1500, density::hard, material::pearl);
  cover->print();
  cout << endl;
  delete cover;

  cover = new reactive("HK22", 2, 1500, density::hard, material::solid);
  cover->print();
  cout << endl;
  delete cover;

  return 0;
}
