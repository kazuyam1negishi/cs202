/**
 * @file bowling_ball_good_test_01.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This test will validate the functionality of the
 * drill_ball() and set_hook_potential() member functions of the
 * bowling_ball class
 * 
 * Subsequently, this will also test the compute_differential
 * function of the core_type class from within drill_ball()
 * 
 * Subsequently, this will also test a variety of getters from 
 * the core_type and coverstock_type classes.
 * 
 * Finally, this test should not generate any memory leaks.
 *
 */

#include "bowling_ball.hpp"

int main(int argc, char const* argv[]) {
  core_type* core = new symmetric_core("PowerCor", 1, 10, 2.5, true,
                                       symmetric_geometry::lightbulb);

  coverstock_type* coverstock =
      new reactive("HK11", 4.f, 1000, density::medium, material::pearl);

  bowling_ball* ball = new bowling_ball("Cuda", core, coverstock);
  ball->print();
  cout << endl;

  // Drill ball after creation
  ball->drill_ball(4, 4, 2);
  ball->print();
  cout << endl;

  // re-drill ball after creation
  ball->drill_ball(6, 4, 0);
  ball->print();
  cout << endl;

  delete ball;
  return 0;
}
