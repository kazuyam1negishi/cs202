/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Coverstock type class
    Input: Name, mass, grit and oil absorption rate
    Output: Bowling ball coverstock info
*/

#ifndef COVERSTOCK_HPP
#define COVERSTOCK_HPP

#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

class coverstock_type {
 private:
  string name;
  float mass;
  int grit;
  float oil_absorption_rate;

 protected:
  void set_oil_absorption_rate(float);

 public:
  static const int GRIT_BASE = 500;
  
  coverstock_type(string, float, int);

  /* Getter functions don't need a virtual classification */
  string  get_name()  const { return(name); }
  float   get_mass()  const { return(mass); }
  int     get_grit()  const { return(grit); }
  float   get_oil_absorption_rate() const { return(oil_absorption_rate); }

  void set_grit(int);
  
  // DONE - function declarations
  virtual void print() const = 0;
  virtual ~coverstock_type(){}
};

// DONE - parameterized constructor
coverstock_type::coverstock_type(string name, float mass, int grit) {
  this->name = name;
  this->mass = mass;
  this->grit = grit;
}

void coverstock_type::set_oil_absorption_rate(float oil_absorption_rate) {
  this->oil_absorption_rate = oil_absorption_rate;
}

// DONE - Grit setting function
void coverstock_type::set_grit(int grit) {
  string lesser_grit = "!Error:\tCannot sand to a grit lower than 500";
  string greater_grit = "!Error:\tCannot polish to a grit higher than 4000";
  string sanding = "Sanding the coverstock to a lower grain";
  string polishing = "Polishing the coverstock to a finer grain";
  // Error checking.
  if(grit < 500){
    cout << lesser_grit << endl;
    exit(1);
  }
  if(grit > 4000) {
    cout << greater_grit << endl;
    exit(1);
  }
  // Compare current grit value;
  if(this->grit < grit){
    cout << sanding << endl;
    this->grit = grit;
  }
  if(this->grit > grit) {
    cout << polishing << endl;
    this->grit = grit;
  }
}

#endif  // COVERSTOCK_HPP