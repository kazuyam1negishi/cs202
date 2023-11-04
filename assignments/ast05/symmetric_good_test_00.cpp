/**
 * @file symmetric_good_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test is designed to validate the creation of a symmetric
 * core. The instantiated object should be capable of invoking its own
 * members directly or though a common sink function.
 *
 */

#include "symmetric.hpp"

void print(core_type* core) { core->print(); }

int main(int argc, char const* argv[]) {
  symmetric_core* core = new symmetric_core("PowerCor", 1, 12, 4.5f, true,
                                            symmetric_geometry::lightbulb);
  core->print();
  cout << endl;
  delete core;

  core = new symmetric_core("PowerCor", 1, 12, 4.5f, true,
                            symmetric_geometry::lightbulb);
  print(core);
  cout << endl;
  delete core;

  return 0;
}
