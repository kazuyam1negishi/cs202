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
 * @brief Takes chars in a string and adds offset for encryption.
 *
 * @param message - message to be encrypted
 * @param offset - character offset for all chars in message
 * @return tempMessage - final message with offset added
 * 
 * @details
 * If you write this function correctly, it should
 * only be 4 lines of code within the function.
 */
string offset(string message, int offset) {
  // Your Code Here
  string tempMessage;
  for (int i = 0; i < message.length(); i++){
    tempMessage += (message[i] + offset);
  }
  return(tempMessage);
}

/**
 * @brief Demonstrates the efficacy of the offset function
 */
void offset_encryption() {
  int s = 5;
  /*string message =
      "\nThis is a test of the offset protocol"
      "\n\tHow does your protocol "
      "handle the newline and offset in?"
      "\nTechnically, this is a very dangerous"
      " practice and should be avoided.";*/
  // Your Code Here
  string message = "The orange cat, sleeping quietly, awoke.";
  cout << "Text : " << message << endl << endl;
  message = offset(message, s);
  cout << "Cipher: " << message << endl << endl;
  message = offset(message, -s);
  cout << "DeCipher: " << message << endl << endl;
}

/**
 * @brief Opens filestream. Returns error if failed.
 *
 * @param str - file to be opened, filename
 * @return ifstream
 */
ifstream _open_input_file(string str) {
  // Your Code Here
  ifstream fileReader;
  fileReader.open(str);
  if(fileReader.fail()){
    cout << endl << "ERROR: Could not open file : " << str << endl;
    exit(-1);
  }
  return(fileReader);
}

/**
 * @brief Opens file to read from. Returns error if failed.
 *
 * @param argc main function formal parameter
 * @param argv main function formal parameter
 * @return ifstream
 */
ifstream open_argv_file(int argc, const char** argv) {
  // Your Code Here
  ifstream fileReader;
  if(argc > 2 || argc < 2){
    cout << endl << "ERROR: Incorrect usage!" << endl
      << "./a.out <filename>" << endl;
    exit(-1);
  }
  if(argc == 2){
    fileReader = _open_input_file(argv[1]);
  }
  return(fileReader);
}

/**
 * @brief Prompts for file to open and read from.
 * 
 * @return ifstream
 */
ifstream open_input_file() {
  // Your Code Here
  ifstream fileReader;
  string fileName;
  cout << "Please enter the name of your input file: " << endl;
  cin >> fileName;
  fileReader = _open_input_file(fileName);
  return(fileReader);
}

/**
 * @brief Opens file to write to.
 *
 * @param fileName - file name
 * @return ifstream
 */
ofstream _open_output_file(string fileName) {
  // Your Code Here
  ofstream fileWriter;
  fileWriter.open(fileName);
  return(fileWriter);
}

/**
 * @brief Prompts for file to open and write to.
 * 
 * @return ofstream
 */
ofstream open_output_file() {
  ofstream fileWriter;
  string fileName;
  cout << "Please enter the name of your output file: " << endl;
  cin >> fileName;
  fileWriter = _open_output_file(fileName);
  return(fileWriter);
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
  int offsetValue;
  string inputStream;

  cout << "What is your shift key? ";
  cin >> offsetValue;

  // Your Code Here
  while(input.eof() == false){
    getline(input, inputStream);
    inputStream = offset(inputStream, offsetValue);
    output << inputStream << endl;
  }
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
string rotate(string message, int offset) {
  // Your Code Here
  int swap;
  int strLength = message.length();
  string tempMessage;
  if(offset % strLength == 0){
    return(message);
  }
  if(offset <= 0){
    swap = offset * -1;
  }
  if(offset > 0){
    swap = strLength - offset;
  }
  for(int i = 0; i < strLength; i++){
    if(swap > strLength - 1){
      swap = 0;
    }
    tempMessage += message[swap];
    swap++;
  }
  return(tempMessage);
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
    for(int i = 0; i < es.stages; i++){
      message = rotate(message, es.rotate[i]);
      message = offset(message, es.offset[i]);
    }
  } else if (scheme == 'D' || scheme == 'd') {
    for(int i = 0; i < es.stages; i++){
      message = offset(message, es.rotate[-i]);
      message = rotate(message, es.offset[-i]);
    }
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

  sequential_file_encryption
    (open_output_file(), open_argv_file(argc, argv));

  rotation_file_encryption();

  return 0;
}
