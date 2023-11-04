/**
 * @file symmetric_good_test_01.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief 
 *  This test is devised to validate the 
 * axis_to_string() and geometry_to_string() 
 * member function of the symmetric data type.
 */

#include "symmetric.hpp"

int main(int argc, char const* argv[]) {
  symmetric_core* core = new symmetric_core("PowerCor", 1, 12, 4.5f, true,
                                            symmetric_geometry::lightbulb);
  core->print();
  cout << endl;
  delete core;

  // validate axis_to_string()
  core = new symmetric_core("PowerCor", 1, 12, 4.5f, false,
                            symmetric_geometry::lightbulb);
  core->print();
  cout << endl;
  delete core;

  /* The following 3 creations/prints validate the geometry_tostring */
  core = new symmetric_core("PowerCor", 1, 12, 4.5f, true,
                            symmetric_geometry::sphere);
  core->print();
  cout << endl;
  delete core;

  core = new symmetric_core("PowerCor", 1, 12, 4.5f, true,
                            symmetric_geometry::oval);
  core->print();
  cout << endl;
  delete core;

  core = new symmetric_core("PowerCor", 1, 12, 4.5f, true,
                            symmetric_geometry::other);
  core->print();
  cout << endl;
  delete core;

  return 0;
}
