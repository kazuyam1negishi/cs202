/**
 * @file simulation_test_03.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  Here it is, the final culmination of all you have been working towards.
 * This test will attempt to use everything, we have made to give
 * a bowler the best chance at hitting a strike every frame.
 *
 * Given a collection of bowling balls, at every frame, select which
 * ball has the best chance of hitting of pocket using the
 * compute_board_track() method. The logic for which can be found in the
 * writeup.
 *
 * Once you have computed which ball to use, provide that ball to
 * the transition_oil function.
 *
 * Repeat this process 10 times to complete the game.
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
  const int BALL_COUNT = 5;
  const int FRAMES = 20;
  const int BOARD_LIMIT = 20;
  lane_type* lane = new lane_type(layout_ids::cheetah);

  bowling_ball* best_ball = nullptr;
  float final_board;
  float best_ball_final_board = 40;  // impossible value

  bowling_ball** ball_bag = new bowling_ball*[BALL_COUNT];
  *(ball_bag + 0) = generate_ball_1();
  *(ball_bag + 1) = generate_ball_2();
  *(ball_bag + 2) = generate_ball_3();
  *(ball_bag + 3) = generate_ball_4();
  *(ball_bag + 4) = generate_ball_5();

  for (int i = 0; i < FRAMES; i++) {
    for (int i = 0; i < BALL_COUNT; i++) {
      final_board =
          BOARD_LIMIT - lane->compute_board_track(*(ball_bag + i), false);
      if (final_board > 0 && final_board < best_ball_final_board) {
        best_ball_final_board = final_board;
        best_ball = *(ball_bag + i);
      }
    }
    cout << best_ball->get_name() << "\t";
    lane->transition_oil(best_ball, false);
    lane->print();
  }

  for (int i = 0; i < BALL_COUNT; i++) delete *(ball_bag + i);
  delete[] ball_bag;

  delete lane;
  return 0;
}
