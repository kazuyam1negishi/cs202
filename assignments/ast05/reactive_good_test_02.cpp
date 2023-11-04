/**
 * @file reactive_good_test_02.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *   The reactive coverstock type is an extension of the performace
 * class which itself is an extension of the coverstock_type.
 *
 * Therefore, if you have a pointer that is of any of those types, you
 * should be able to instantiate a reactive coverstock.
 *
 * This test will attempt to instantiate a reactive coverstock by all 3
 * means and attempt to feed each of those pointers into a common sink
 * function.
 * 
 */

#include "reactive.hpp"

void print(coverstock_type* cover) { cover->print(); }

int main(int argc, char const* argv[]) {
  // Simple reactive
  reactive* C1 =
      new reactive("HK22", 2, 1500, density::medium, material::pearl);

  C1->print();
  cout << endl;
  print(C1);
  cout << endl;

  // Performance pointer
  performance* C2 =
      new reactive("HK22", 2, 1500, density::medium, material::pearl);

  C2->print();
  cout << endl;
  print(C2);
  cout << endl;

  // Performance pointer
  coverstock_type* C3 =
      new reactive("HK22", 2, 1500, density::medium, material::pearl);

  C3->print();
  cout << endl;
  print(C3);
  cout << endl;

  return 0;
}
