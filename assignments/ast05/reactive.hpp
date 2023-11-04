/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Reactive coverstock class
    Input: Name, mass, grit and hardness
    Output: Reactive coverstock info
*/

#ifndef REACTIVE_HPP
#define REACTIVE_HPP

#include "performance.hpp"

enum material { solid, pearl, hybrid };

class reactive : public performance {
 private:
  const float REACTIVE_BASE_RATE = 0.7f;
  material compound;

 public:
  reactive(string, float, int, density, material); 
  string material_to_string() const; 

  float compute_oil_absorption_rate(); 
  void print() const; 

  ~reactive(){}
};

// DONE - parameterized constructor
reactive::reactive(string name, float mass, int grit, density hardness,
                   material compound)
    : performance(name, mass, grit, hardness) {
  this->compound = compound;
  coverstock_type::set_oil_absorption_rate(compute_oil_absorption_rate());
}

// DONE - Material string function
string reactive::material_to_string() const {
  string ballMaterial;
  switch(this->compound){
    case solid:
      ballMaterial = "Solid";
      break;
    case pearl:
      ballMaterial = "Pearl";
      break;
    case hybrid:
      ballMaterial = "Hybrid";
      break;
    default:
      break;
  }
  return(ballMaterial);
}

// DONE - Oil absorption calculator
float reactive::compute_oil_absorption_rate() {
  float compoundRate;
  switch(this->compound){
    case solid:
      compoundRate = 0.65f;
      break;
    case pearl:
      compoundRate = 0.9f;
      break;
    case hybrid:
      compoundRate = 0.7f;
      break;
    default:
      break;
  }
  compoundRate = compoundRate * REACTIVE_BASE_RATE;
  compoundRate = compoundRate * performance::compute_oil_absorption_rate();
  return(compoundRate);
}

void reactive::print() const {
  cout << "Performance Coverstock statistics" << endl
       << "\tName: "                << this->get_name() << endl 
       << "\tCoverstock Type:     " << this->hardness_to_string() 
       << " "                       << this->material_to_string() << endl
       << "\tCoverstock Grit:     " << this->get_grit() << " grit" << endl
       << "\tOil absorption Rate: " << this->get_oil_absorption_rate() << endl;
}

#endif