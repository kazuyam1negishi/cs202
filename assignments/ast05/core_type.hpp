/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Core type class
    Input: Name, core and pancake masses and radius of gyration
    Output: Core info
*/

#ifndef CORE_TYPE_HPP
#define CORE_TYPE_HPP

#include <string>
using std::string;

class core_type {
 private:
  string name;
  float pancake_mass;
  float core_mass;

 protected:
  // Radius of gyration (2.4 - 2.8, lower value -> earlier hook)
  float rg;
  // Track flare potential (0 - 0.8, higher value -> agressive hook)
  float differential;

 public:
  core_type(string, float, float, float);

  // DONE - getter functions
  string get_name() const {
    return(name);
  } 
  float get_pancake_mass() const {
    return(pancake_mass);
  } 
  float get_core_mass() const {
    return(core_mass);
  } 
  float get_mass() const {
    return(core_mass + pancake_mass);
  } 
  float get_rg() const { 
    return(rg);
  } 
  float get_differential() const {
    return(differential);
  };

  // DONE - virtual and pure virtual declarations
  virtual void compute_differential(const float*) = 0;
  virtual string geometry_to_string() const = 0;
  virtual void print() const = 0;
  virtual ~core_type(){}
};

core_type::core_type(string name, float pancake_mass, float core_mass, float rg) {
  this->name = name;
  this->pancake_mass = pancake_mass;
  this->core_mass = core_mass;
  this->rg = rg;
}

#endif