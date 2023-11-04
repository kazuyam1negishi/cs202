/**
 * @file asymmetric_good_test_01.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test is devised to validate the
 * geometry_to_string() and compute_intermediate_differential()
 * member functions of the asymmetric data type.
 */

#include "asymmetric.hpp"

int main(int argc, char const* argv[]) {
  asymmetric_core* core = new asymmetric_core("Ellipticon", 0, 13, 4.5f,
                             asymmetric_geometry::triangle);
  core->print();
  cout << endl;
  delete core;

  core = new asymmetric_core("Ellipticon", 0, 13, 4.5f,
                             asymmetric_geometry::rectangle);
  core->print();
  cout << endl;
  delete core;

  core = new asymmetric_core("Ellipticon", 0, 13, 4.5f,
                             asymmetric_geometry::polygon);
  core->print();
  cout << endl;
  delete core;


  return 0;
}
