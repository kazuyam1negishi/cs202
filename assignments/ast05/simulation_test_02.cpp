/**
 * @file simulation_test_02.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  Once you pass the prior 2 tests you should be able to pass this
 * test with no problem.
 *
 * This test will use the transition_oil function but with different
 * balls on each transition. The goal of this test is to observe that
 * different bowling balls will transfer oil at different rates.
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

bowling_ball* generate_ball_5() {
  core_type* core = new symmetric_core("Capacitor", 0, 12, 2.5, true,
                                       symmetric_geometry::lightbulb);
  coverstock_type* coverstock =
      new urethane("Pitch Black", 3, 1000, density::soft);

  bowling_ball* ball = new bowling_ball("Pitch Black", core, coverstock);
  ball->drill_ball(4, 4, 2);
  return ball;
}

int main(int argc, char const* argv[]) {
  lane_type* lane = new lane_type(layout_ids::cheetah);

  // Base line bowling ball
  bowling_ball* sym_ball = generate_ball_1();
  cout << "Lane condition after ball 1: ";
  lane->transition_oil(sym_ball, true);

  // Same core as sym_ball with a different coverstock
  bowling_ball* sym_ball_2 = generate_ball_2();
  cout << "Lane condition after ball 2: ";
  lane->transition_oil(sym_ball_2, true);

  // Asymmetric bowling ball
  bowling_ball* asym_ball = generate_ball_3();
  cout << "Lane condition after ball 3: ";
  lane->transition_oil(asym_ball, true);

  // House plastic ball
  bowling_ball* house_ball = generate_ball_4();
  cout << "Lane condition after ball 4: ";
  lane->transition_oil(house_ball, true);

  // House plastic ball
  bowling_ball* urethane_ball = generate_ball_5();
  cout << "Lane condition after ball 5: ";
  lane->transition_oil(urethane_ball, true);

  delete sym_ball;
  delete sym_ball_2;
  delete asym_ball;
  delete house_ball;
  delete urethane_ball;
  delete lane;
  return 0;
}
