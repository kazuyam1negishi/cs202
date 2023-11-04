/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Performance coverstock class
    Input: Name, mass, grit and hardness
    Output: Performance coverstock info
*/

#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP

#include "coverstock_type.hpp"

enum density { soft, medium, hard };

class performance : public coverstock_type {
 private:
  density hardness;

 protected:
  // DONE - function declaration
  float compute_oil_absorption_rate();
 public:
  performance(string, float, int, density);

  string hardness_to_string() const; 

  virtual ~performance(){}
};

// DONE - parameterized constructor
performance::performance(string name, float mass, int grit, density hardness)
    : coverstock_type(name, mass, grit) {
  this->hardness = hardness;
}

// DONE - Hardness string function
string performance::hardness_to_string() const {
  string densHardness;
  switch(this->hardness){
    case soft:
      densHardness = "Soft";
      break;
    case medium:
      densHardness = "Medium";
      break;
    case hard:
      densHardness = "Hard";
      break;
    default:
      break;
  }
  return(densHardness);
}

// DONE - Oil absorption setter function
float performance::compute_oil_absorption_rate() {
  float oilAbsorb;
  switch(this->hardness){
    case soft:
      oilAbsorb = 1.5f;
      break;
    case medium:
      oilAbsorb = 1.f;
      break;
    case hard:
      oilAbsorb = 0.8f;
      break;
    default:
      break;
  }
  return(oilAbsorb);
}

#endif // PERFORMANCE_HPP