/**
 * @file simulation_test_01.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test will validate the transition_oil member function of the
 * lane_type class
 *
 */

#include "lane_type.hpp"

bowling_ball* generate_ball_3() {
  core_type* core = new asymmetric_core("Gas Mask", 1.5, 10.5, 2.5,
                                        asymmetric_geometry::polygon);
  coverstock_type* coverstock =
      new reactive("HK22", 3, 1000, density::hard, material::hybrid);

  bowling_ball* ball = new bowling_ball("Black Widow", core, coverstock);
  ball->drill_ball(3, 4, 2);
  return ball;
}

int main(int argc, char const* argv[]) {
  lane_type* lane = new lane_type(layout_ids::cheetah);

  bowling_ball* ball = generate_ball_3();

  lane->print();
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);
  lane->transition_oil(ball, true);

  delete ball;
  delete lane;
  return 0;
}
