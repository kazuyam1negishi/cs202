/**
 * @file bowling_ball_good_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  One you have validated the coverstock_type, core_type, and all
 * subsequent children; you will be able to create bowling balls by
 * creating a coverstock and core object and using them to create
 * a bowling ball.
 * This set of bowling_ball tests are predicated on that fact.
 *
 * This test will test the constructor, destructor, and print functions
 *
 * This test should not produce any errors or have any memory leaks
 */

#include "bowling_ball.hpp"

int main(int argc, char const* argv[]) {
  core_type* core = new symmetric_core("PowerCor", 1, 10, 2.5, true,
                                       symmetric_geometry::lightbulb);

  coverstock_type* coverstock =
      new reactive("HK11", 4.f, 1000, density::medium, material::pearl);

  bowling_ball* ball = new bowling_ball("Cuda", core, coverstock);
  ball->print();

  delete ball;
  
  return 0;
}
