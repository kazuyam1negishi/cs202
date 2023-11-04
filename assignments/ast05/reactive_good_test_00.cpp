/**
 * @file reactive_good_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test will validate the constructor for the reactive class
 *
 * Subsequently this will also test reactive's implementation of the
 * compute_oil_absorption_rate()
 *
 * and
 *
 * performance's implementations of
 * hardness_to_string() and compute_oil_absorption_rate();
 *
 */

#include "reactive.hpp"

int main(int argc, char const* argv[]) {
  reactive* C1 =
      new reactive("HK22", 2, 1500, density::medium, material::pearl);

  C1->print();
  cout << endl;
}