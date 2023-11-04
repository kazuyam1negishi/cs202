/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Lane type class
    Input: Layout chosen
    Output: Lane info with given bowling ball in function parameters
*/

#ifndef LANE_TYPE_H
#define LANE_TYPE_H

#include "bowling_ball.hpp"
#include "oil_pattern.hpp"

class lane_type {
 private:
  oil_pattern* pattern;

 public:
  lane_type(layout_ids);

  float compute_board_track(bowling_ball*, bool) const;
  void transition_oil(bowling_ball*, bool);

  void print() const;

  ~lane_type();
};

lane_type::lane_type(layout_ids layout) { pattern = new oil_pattern(layout); }

void lane_type::print() const { pattern->print(); }

lane_type::~lane_type() { delete pattern; }

float lane_type::compute_board_track(bowling_ball* ball, bool debug) const {
  cout << fixed << setprecision(2);

  const float OIL_BOARDS_PER_SEGMENT = -2.f;
  const float HOOK_BOARDS_PER_SEGMENT = 2.5f;

  float hook_potential = ball->get_hook_potential();
  float* oil_volume_segments = pattern->get_oil_volume_segments();

  float current_board = 20.f;  

  float glide_transition, hook_transition;

  for (int i = 0; i < BOARD_SEGMENTS; i++) {
    if (debug) cout << "Current Board: " << current_board << endl;
    /* YOUR CODE HERE */
    glide_transition = OIL_BOARDS_PER_SEGMENT * oil_volume_segments[i];
    hook_transition = ((1 - oil_volume_segments[i]) * HOOK_BOARDS_PER_SEGMENT) * hook_potential;

    current_board += (glide_transition + hook_transition);
  }
  if (debug) cout << "Final Board:   " << current_board << endl << endl;

  return current_board;
}

void lane_type::transition_oil(bowling_ball* ball, bool debug) {
  const float MAX_OIL_ABSORBED = 0.03f;
  const float MAX_OIL_DISSIPATED = 0.01f;

  float oil_volume = 0.f;
  float oil_absorbed = 0.f;

  float oil_absorption_rate = ball->get_coverstock_type()->get_oil_absorption_rate();
  float* oil_volume_segments = pattern->get_oil_volume_segments();

  cout << fixed << setprecision(3);
  for (int i = 0; i < BOARD_SEGMENTS; i++) {
    oil_volume = ((oil_volume_segments[i] * MAX_OIL_ABSORBED) * oil_absorption_rate);
    oil_volume_segments[i] -= oil_volume;
    oil_absorbed += oil_volume;

    oil_volume = oil_absorbed * MAX_OIL_DISSIPATED;
    oil_absorbed -= oil_volume;
    oil_volume_segments[i] += oil_volume;
  }
  if (debug) pattern->print();
}
#endif  // LANE_TYPE_H
