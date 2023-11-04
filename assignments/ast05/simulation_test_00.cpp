/**
 * @file simulation_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  This simulation test is designed to test the validity of the
 * compute_board_track function of the lane class
 *
 */

#include "lane_type.hpp"

bowling_ball* generate_ball_1() {
  core_type* core = new symmetric_core("DynamiCor", 1, 10, 2.5, true,
                                       symmetric_geometry::lightbulb);
  coverstock_type* coverstock =
      new reactive("HK22-ERT", 4.f, 1500, density::medium, material::pearl);

  bowling_ball* ball = new bowling_ball("Cuda", core, coverstock);
  ball->drill_ball(4, 4, 2);
  return ball;
}

bowling_ball* generate_ball_2() {
  core_type* core = new symmetric_core("DynamiCor", 1, 10, 2.5, true,
                                       symmetric_geometry::lightbulb);
  coverstock_type* coverstock =
      new reactive("Reactive", 4.f, 1200, density::medium, material::solid);

  bowling_ball* ball = new bowling_ball("Cuda", core, coverstock);
  ball->drill_ball(4, 4, 2);
  return ball;
}

bowling_ball* generate_ball_3() {
  core_type* core = new asymmetric_core("Gas Mask", 1.5, 10.5, 2.5,
                                        asymmetric_geometry::polygon);
  coverstock_type* coverstock =
      new reactive("HK22", 3, 1000, density::hard, material::hybrid);

  bowling_ball* ball = new bowling_ball("Black Widow", core, coverstock);
  ball->drill_ball(3, 4, 2);
  return ball;
}

bowling_ball* generate_ball_4() {
  core_type* core =
      new symmetric_core("Basic", 0, 8, 0, true, symmetric_geometry::sphere);
  coverstock_type* coverstock = new plastic("Plastic", 2, 4000);

  bowling_ball* ball = new bowling_ball("House", core, coverstock);
  ball->drill_ball(4, 4, 2);
  return ball;
}

void test_ball(lane_type* lane, bowling_ball* ball) {
  cout << "Testing" << endl;
  ball->print();
  lane->compute_board_track(ball, true);
}

int main(int argc, char const* argv[]) {
  lane_type* lane = new lane_type(layout_ids::cheetah);

  // Base line bowling ball
  bowling_ball* sym_ball = generate_ball_1();
  test_ball(lane, sym_ball);

  // Same core as sym_ball with a different coverstock
  bowling_ball* sym_ball_2 = generate_ball_2();
  test_ball(lane, sym_ball_2);

  // Asymmetric bowling ball
  bowling_ball* asym_ball = generate_ball_3();
  test_ball(lane, asym_ball);

  // House plastic ball
  bowling_ball* house_ball = generate_ball_4();
  test_ball(lane, house_ball);

  delete sym_ball;
  delete sym_ball_2;
  delete asym_ball;
  delete house_ball;
  delete lane;
  return 0;
}
