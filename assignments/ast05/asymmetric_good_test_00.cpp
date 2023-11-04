/**
 * @file asymmetric_good_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *   This test is designed to validate the creation of an asymmetric
 * core. The instantiated object should be capable of invoking its own
 * members directly or though a common sink function.
 *
 */

#include "asymmetric.hpp"

void print(core_type* core) { core->print(); }

int main(int argc, char const* argv[]) {
  asymmetric_core* core = new asymmetric_core("Ellipticon", 0, 13, 4.5f,
                                              asymmetric_geometry::triangle);
  core->print();
  cout << endl;
  delete core;

  core = new asymmetric_core("Ellipticon", 0, 13, 4.5f,
                             asymmetric_geometry::triangle);
  print(core);
  cout << endl;
  delete core;

  return 0;
}
