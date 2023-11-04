/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 5
    Description: Oil pattern class
    Input: Layout chosen
    Output: Layout of lane and oil patterns
*/

#ifndef OIL_PATTERN_H
#define OIL_PATTERN_H

#include <iomanip>
using std::setw, std::setprecision, std::fixed;

enum layout_ids { cheetah, scorpion, shark };

/* Possible oil layouts */
const int BOARD_SEGMENTS = 12;
const float CHEETAH_PATTERN[BOARD_SEGMENTS] = 
  {1, .95f, .9f, .85f, .8f, .7f, 0.5f, 0, 0, 0, 0 , 0};
const float SCORPION_PATTERN[BOARD_SEGMENTS] = 
  {1, 1, .9f, .8f, .8f, .7f, 0.6f, .5f, .3f, 0, 0, 0};
const float SHARK_PATTERN[BOARD_SEGMENTS] = 
  {1, 1, .8f, .7f, .68f, .65f, 0.6f, .52f, .5f, .4f, 0, 0};

class oil_pattern {
 private:
  string name;
  layout_ids layout; 
  float* oil_volume_segments;

 public:
  oil_pattern(layout_ids);

  // DONE - getter function
  float* get_oil_volume_segments() { return oil_volume_segments; }

  void copy_oil_volume_segments();
  string layout_to_string();

  void print();

  ~oil_pattern();
};

oil_pattern::oil_pattern(layout_ids layout) {
  this->layout = layout;
  name = layout_to_string();

  oil_volume_segments = new float[BOARD_SEGMENTS];
  copy_oil_volume_segments();
};

// DONE - Layout string function
string oil_pattern::layout_to_string() {
  string laneLayout;
  switch(layout){
    case cheetah:
      laneLayout = "Cheetah";
      break;
    case scorpion:
      laneLayout = "Scorpion";
      break;
    case shark:
      laneLayout = "Shark";
      break;
    default:
      break;
  }
  return(laneLayout);
}

// DONE - Oil pattern copier
void oil_pattern::copy_oil_volume_segments() {
  for(int i = 0; i < BOARD_SEGMENTS; i++){
    switch(layout){
      case cheetah:
        oil_volume_segments[i] = CHEETAH_PATTERN[i];
        break;
      case scorpion:
        oil_volume_segments[i] = SCORPION_PATTERN[i];
        break;
      case shark:
        oil_volume_segments[i] = SHARK_PATTERN[i];
        break;
    }
  }
}

void oil_pattern::print() {
  cout << setprecision(4) << setw(8) << "Current pattern: ";
  for (int i = 0; i < BOARD_SEGMENTS; i++)
    if(i < 11) {
        cout << setw(5) << *(oil_volume_segments + i) << ",";
    }
    else {
        cout << setw(5) << *(oil_volume_segments + i);
    }
  cout << "\n";
}

// DONE - destructor
oil_pattern::~oil_pattern() {
  delete [] oil_volume_segments;
}

#endif // OIL_PATTERN_H
