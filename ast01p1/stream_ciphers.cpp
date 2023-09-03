/**
 * @file 
 * @author 
 *
 * @brief 
 *
 * @date
 */

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

#include <string>
using std::getline;
using std::string;

struct scheme_parameters {
  static const int stages = 3;
  int rotate[stages] = {22, 4, 40};
  int offset[stages] = {2, 4, 8};
};

/**
 * @brief 
 *
 * @param 
 * @param 
 * @return 
 * 
 * @details
 * If you write this function correctly, it should
 * only be 4 lines of code within the function.
 */
string offset(string message, int offset) {
  // Your Code Here
}

/**
 * @brief Demonstrates the efficacy of the offset function
 */
void offset_encryption() {
  int s = 5;
  string message =
      "\nThis is a test of the offset protocol\n\tHow does your protocol "
      "handle the newline and offset in?\nTechnically, this is a very dangerous"
      " practice and should be avoided.";

  // Your Code Here

}

/**
 * @brief 
 *
 * @param  
 * @return ifstream
 */
ifstream _open_input_file(string) {
  // Your Code Here
}

/**
 * @brief 
 *
 * @param argc main function formal parameter
 * @param argv main function formal parameter
 * @return ifstream
 */
ifstream open_argv_file(int argc, const char** argv) {
  // Your Code Here
}

/**
 * @brief 
 * 
 * @return ifstream
 */
ifstream open_input_file() {
  // Your Code Here
}

/**
 * @brief 
 *
 * @param 
 * @return ifstream
 */
ofstream _open_output_file(string file_name) {
  // Your Code Here
}

/**
 * @brief 
 * 
 * @return ofstream
 */
ofstream open_output_file() {
}

/**
 * @brief Demonstrate the efficacy of the following functions
 *  open_input_file
 *  open_output_file
 *  offset
 *
 * @param output ofstream output file id
 * @param input ifstream input file id
 */
void sequential_file_encryption(ofstream output, ifstream input) {
  int offset_value;
  string input_stream;

  cout << "What is your shift key? ";
  cin >> offset_value;

  // Your Code Here
}

/**
 * @brief 
 *
 * @param 
 * @param 
 * @return string
 *
 * @details
 * 
 *  Remember, no:
 *  1) Use of modulus or division operations within looping constructs
 *  2) Rotations greater than the length of the array must be reduced
 *  3) multiple iterations over the same elements of either array
 *  4) No built in functions other than length
 * 
 *  Engaging in any subset of these restrictions will result in 0 points
 */
string rotate(string, int) {
  // Your Code Here
}

/**
 * @brief 
 * 
 * @return string
 */
string rotation_encryption(string message) {
  scheme_parameters es;
  char scheme;

  cout << "Are you encrypting(E) or decrypting(D)? ";
  cin >> scheme;

  if (scheme == 'E' || scheme == 'e') {
    // Your Code here
  } else if (scheme == 'D' || scheme == 'd') {
    // Your Code Here
  } else {
    cerr << "ERROR: Encryption scheme unrecognized!" << endl;
  }
  return message;
}

/**
 * @brief Function to retrieve the password that unlocks
 * the second part of this assignment
 */
void rotation_file_encryption() {
  string message;
  ifstream input = open_input_file();
  getline(input, message);
  cout << rotation_encryption(message) << endl;
}

int main(int argc, char const** argv) {
  offset_encryption();

  // sequential_file_encryption(open_output_file(), open_argv_file(argc, argv));

  // rotation_file_encryption();

  return 0;
}
