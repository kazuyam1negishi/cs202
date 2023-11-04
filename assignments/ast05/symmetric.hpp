/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Asymmetric core type class
    Input: core_type vars, plus geometry
    Output: Bowling ball core info
*/

#ifndef SYMMETRIC_HPP
#define SYMMETRIC_HPP

#include <iostream>

#include "core_type.hpp"

using std::cout, std::endl;

enum symmetric_geometry { sphere, lightbulb, oval, other };

class symmetric_core : public core_type {
 private:
  bool axis;
  symmetric_geometry shape;

 public:
  symmetric_core(std::string, float, float, float, bool, symmetric_geometry);

  string axis_to_string() const;

  ~symmetric_core(){}

  // DONE - function redeclarations
  void compute_differential(const float*);
  string geometry_to_string() const;
  void print() const;
};

string symmetric_core::axis_to_string() const {
  if (axis) return "Ball is axisymmetric ";
  return "Ball is non-axisymmetric";
}

// DONE - parameterized constructor
symmetric_core::symmetric_core(std::string nam, float pancake,
  float core, float gyro, bool ax, symmetric_geometry sha)
  :core_type(nam, pancake, core, gyro){
    core_type::differential = 0;
    axis = ax;
    shape = sha;
}


/**
 * @brief
 *  Provides a description of a symmetric bowling ball
 */
void symmetric_core::print() const {
  cout << "Symmetric bowling ball statistics" << endl
       << "\tName: " << get_name() << endl
       << "\tPancake weight: " << get_pancake_mass() << endl
       << "\tCore shape:  " << geometry_to_string() << endl
       << "\tCore weight: " << get_mass() << " lbs" << endl
       << "\tSymmetry: " << axis_to_string() << endl
       << "\tRadius of Gyration: " << rg << endl
       << "\tDifferential: " << differential << endl;
}

// DONE - Geometry string function
string symmetric_core::geometry_to_string() const {
  switch(this->shape){
    case sphere:
      return("Sphere");
      break;
    case lightbulb:
      return("Lightbulb");
      break;
    case oval:
      return("Oval");
      break;
    case other:
      return("Other");
      break;
  }
  return("Other");
}

// DONE - PTP calculator
void symmetric_core::compute_differential(const float* drill_layout) {
  const float PTVR = 0.3f,  // Pin to VAL ratio
      OFFSET_MAX = 6,       // Maximum length from PaP
      DIFF_MAX = 0.6f;      // Maximum differential of a symmetric ball

  float PTP = DIFF_MAX - (DIFF_MAX * PTVR);        // Pin to PaP value
  float PTV = DIFF_MAX - (DIFF_MAX * (1 - PTVR));  // Pin to VAL value

  PTP = ((PTP * drill_layout[0]) / OFFSET_MAX);

  if (*(drill_layout + 2) != 0) {
    PTV = PTV * (1 - (*(drill_layout + 2) / OFFSET_MAX));
  }

  differential = PTP + PTV;
}

#endif  // SYMMETRIC_HPP