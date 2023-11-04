/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Asymmetric core type class
    Input: core_type vars, plus geometry
    Output: Bowling ball core info
*/

#ifndef ASYMMETRIC_HPP
#define ASYMMETRIC_HPP

#include <iostream>

#include "core_type.hpp"

using std::cout, std::endl;

enum asymmetric_geometry { triangle, rectangle, polygon };

class asymmetric_core : public core_type {
 private:
  asymmetric_geometry shape;
  float intermediate_differential;

 public:
  asymmetric_core(string, float, float, float, asymmetric_geometry);

  void compute_intermediate_differential();

  ~asymmetric_core(){}

  // DONE - function redeclarations
  void compute_differential(const float*);
  string geometry_to_string() const;
  void print() const;
};

// DONE - parameterized constructor
asymmetric_core::asymmetric_core(string nam, float pancake,
  float core, float gyro, asymmetric_geometry sha)
  :core_type(nam, pancake, core, gyro){
  intermediate_differential = 0;
  core_type::differential = 0;
  shape = sha;
  compute_intermediate_differential();
};

// DONE - intermediate differential setter
void asymmetric_core::compute_intermediate_differential(){
  switch(this->shape){
    case triangle:
      intermediate_differential += 0.05f;
      break;
    case rectangle:
      intermediate_differential += 0.1f;
      break;
    case polygon:
      intermediate_differential += 0.2f;
      break;
    default:
      break;
  }
}

/**
 * @brief
 *  Provides a description of a symmetric bowling ball
 */
void asymmetric_core::print() const {
  cout << "Asymmetric bowling ball statistics" << endl
       << "\tName: " << get_name() << endl
       << "\tPancake weight: " << get_pancake_mass() << endl
       << "\tCore shape:  " << geometry_to_string() << endl
       << "\tCore weight: " << get_mass() << " lbs" << endl
       << "\tRadius of Gyration: " << rg << endl
       << "\tDifferential: " << differential << endl
       << "\tIntermediate Differential: " << intermediate_differential << endl;
}

// DONE - geometry string function
string asymmetric_core::geometry_to_string() const {
  // Temporary variable to return string
  string ballShape;
  switch(this->shape){
    case triangle:
      ballShape = "Triangle";
      break;
    case rectangle:
      ballShape = "Rectangle";
      break;
    case polygon:
      ballShape = "Polygon";
      break;
    default:
      break;
  }
  return(ballShape);
}

// DONE - Differential calculator
// Returns PTP + PTV to differential before exiting function
void asymmetric_core::compute_differential(const float* drill_layout) {
  const float PTVR = 0.3f,  // Pin to VAL ratio
      OFFSET_MAX = 6,       // Maximum length from PaP
      DIFF_MAX = 0.6f;      // Maximum differential of a symmetric ball

  float PTP = DIFF_MAX - (DIFF_MAX * PTVR);        // Pin to PaP value
  float PTV = DIFF_MAX - (DIFF_MAX * (1 - PTVR));  // Pin to VAL value

  // PTP different from symmetrical
  // as it also adds intermediate diff.
  PTP = ((PTP * drill_layout[0]) / OFFSET_MAX);
  PTP += intermediate_differential;

  if (*(drill_layout + 2) != 0) {
    PTV = PTV * (1 - (*(drill_layout + 2) / OFFSET_MAX));
  }

  differential = PTP + PTV;
}

#endif  // ASYMMETRIC_HPP