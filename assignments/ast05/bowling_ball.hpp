/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Bowling ball class
    Input: Coverstock and core as pointers, and name
    Output: Bowling ball info
*/

#ifndef BOWLING_BALL_HPP
#define BOWLING_BALL_HPP

/* Core type libraries */
#include "asymmetric.hpp"
#include "symmetric.hpp"

/* Coverstock type libraries */
#include "reactive.hpp"
#include "urethane.hpp"
#include "plastic.hpp"

class bowling_ball {
 private:
  const int DRILL_LAYOUT = 3;

  string name;

  float total_mass, hook_potential;
  float* drill_layout;

  core_type* core;
  coverstock_type* coverstock;

 public:
  bowling_ball(string, core_type*, coverstock_type*);

  void set_hook_potential();
  void drill_ball(float, float, float);

  core_type*       get_core_type()       const { return(core); }
  coverstock_type* get_coverstock_type() const { return(coverstock); }
  const float*     get_drill_layout()    const { return(drill_layout); }
  float            get_hook_potential()  const { return(hook_potential); }
  string           get_name()            const { return(name); }

  void print() const;

  ~bowling_ball();
};

// DONE - parameterized constructor
bowling_ball::bowling_ball(string name, core_type* core, coverstock_type* coverstock) {
  this->name = name;
  this->core = core;
  this->coverstock = coverstock;
  total_mass = coverstock->get_mass() + core->get_mass();
  drill_layout = new float [DRILL_LAYOUT];
}

// DONE - destructor
bowling_ball::~bowling_ball() {
  delete core;
  delete coverstock;
  delete [] drill_layout;
}

void bowling_ball::print() const{
  cout << "Bowling Ball: " << name << ", weighs " << total_mass << "-lbs" << endl;
  core->print();
  coverstock->print();
  cout << "Total Hook Potential: " << hook_potential << endl;
}

void bowling_ball::drill_ball(float PtP, float PSAtP, float PtV) {
  drill_layout[0] = PtP;
  drill_layout[1] = PSAtP;
  drill_layout[2] = PtV;
  core->compute_differential(drill_layout);
  set_hook_potential();
}

void bowling_ball::set_hook_potential() {
  const float GRIT_FACTOR = .6f,
              DIFF_FACTOR = .35f,
              RG_FACTOR = .05f;
  hook_potential = ((GRIT_FACTOR*500)/coverstock->get_grit())
    + (core->get_differential() * DIFF_FACTOR)
    + (core->get_rg() * RG_FACTOR);
}

#endif // BOWLING_BALL_HPP
