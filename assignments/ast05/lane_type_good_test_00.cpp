/**
 * @file lane_type_good_test_00.cpp
 * @author Benjamin Zofcin (zofcin@unlv.nevada.edu)
 * @brief
 *  Once the bowling_ball and oil_pattern headers are validated,
 * you are able to create a bowling lane. Since a lane has oil patterns
 * and the ball interacts with the lane only the lane_type is needed here
 *
 * This test will validate the following class member functions of
 * the lane_type:
 *
 * constructor, destructor, print
 *
 * this test should not yield any memory leaks
 *
 */

#include "lane_type.hpp"

int main(int argc, char const* argv[]) {
  lane_type* lane = new lane_type(layout_ids::cheetah);
  lane->print();
  delete lane;
  return 0;
}
