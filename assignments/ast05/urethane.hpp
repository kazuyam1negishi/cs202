/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Urethane coverstock class
    Input: Name, mass, grit and hardness
    Output: Urethane coverstock info
*/

#ifndef URETHANE_HPP
#define URETHANE_HPP

#include "performance.hpp"

class urethane : public performance {
 private:
  const float URETHANE_BASE_RATE = 0.8f;

 public:
  urethane(string, float, int, density);

  float compute_oil_absorption_rate();
  void print() const;
  ~urethane(){}
};

// DONE - parameterized constructor
// Hardness already set with parent constructor
urethane::urethane(string name, float mass, int grit, density hardness)
    : performance(name, mass, grit, hardness) {
  coverstock_type::set_oil_absorption_rate(compute_oil_absorption_rate());
}

// DONE - Oil absorption function
float urethane::compute_oil_absorption_rate() {
  float finalOilRate;
  finalOilRate = ((URETHANE_BASE_RATE * performance::compute_oil_absorption_rate() * GRIT_BASE) / get_grit());
  return(finalOilRate);
}


void urethane::print() const {
  cout << "Urethane Coverstock statistics" << endl
       << "\tName: "                << this->get_name() << endl 
       << "\tCoverstock Type:     " << this->hardness_to_string() << endl
       << "\tCoverstock Grit:     " << this->get_grit() << " grit" << endl
       << "\tOil absorption Rate: " << this->get_oil_absorption_rate() << endl;
}

#endif // URETHANE_HPP
