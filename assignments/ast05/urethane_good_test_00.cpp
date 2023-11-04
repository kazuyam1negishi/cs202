/**
 * @file urethane_good_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test is designed to validate the functionality of the
 * constructor and compute_oil_absorption_rate of the urethane
 *
 */

#include "urethane.hpp"

int main(int argc, char const* argv[]) {
  urethane* cover = new urethane("Urethane", 2, 1000, density::hard);
  cover->print();
  cout << endl;
  delete cover;
  
  cover = new urethane("Urethane", 2, 1000, density::medium);
  cover->print();
  cout << endl;
  delete cover;
 
  cover = new urethane("Urethane", 2, 1000, density::soft);
  cover->print();
  cout << endl;
  delete cover;
 
  return 0;
}
