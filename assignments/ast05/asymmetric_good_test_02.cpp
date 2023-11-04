/**
 * @file asymmetric_good_test_02.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *    This test is designed to validate the functionality of the
 * compute_differential() of the asymmetric data type.
 *
 * ___NOTE___
 *  This test is also related to the bowling_ball data type.
 * In this test case, we are forcing the parameters, rather than
 * relying on the parent class data members.
 */

#include "asymmetric.hpp"

int main(int argc, char const* argv[]) {
  float drill_layout_1[3] = {4, 4, 2};
  float drill_layout_2[3] = {6, 4, 0};

  asymmetric_core* core;

  // Weakest intermediate and total differential
  core = new asymmetric_core("Ellipticon", 0, 13, 4.5f,
                             asymmetric_geometry::triangle);

  core->compute_differential(&drill_layout_1[0]);
  core->print();
  cout << endl;

  core->compute_differential(&drill_layout_2[0]);
  core->print();
  cout << endl;

  delete core;

  // Middiling intermediate and total differential
  core = new asymmetric_core("Ellipticon", 0, 13, 4.5f,
                             asymmetric_geometry::rectangle);

  core->compute_differential(&drill_layout_1[0]);
  core->print();
  cout << endl;

  core->compute_differential(&drill_layout_2[0]);
  core->print();
  cout << endl;

  // Strongest intermediate and total differential
  core = new asymmetric_core("Ellipticon", 0, 13, 4.5f,
                             asymmetric_geometry::polygon);

  core->compute_differential(&drill_layout_1[0]);
  core->print();
  cout << endl;

  core->compute_differential(&drill_layout_2[0]);
  core->print();
  cout << endl;

  return 0;
}
