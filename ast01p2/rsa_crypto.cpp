/*
* Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 1 Part 2
* Description: Encrypts/decrypts a message using RSA encryption.
* Input: File name to use, block size, 2 prime nums, and public key.
* Output: Message after rotation/offset encryption and decryption.
*/ 

/**
 * @file rsa_crypto.cpp
 * @author Jimmy Soto Agustin
 * @brief Encrypts/decrypts a message using RSA encryption.
 * 
 * @date Start: 9/8/2023 - End: 9/10/2023
 */

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cmath>
using std::pow;
using std::sqrt;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::stol;
using std::string;

const int base = 27;

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
 * @brief Prompts for file to open and read from.
 * 
 * @return ifstream
 */
ifstream open_input_file() {
  // Your Code Here
  ifstream fileReader;
  string fileName;
  cout << "Please enter the name of your input file: ";
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
  cout << "Please enter the name of your output file: ";
  cin >> fileName;
  fileWriter = _open_output_file(fileName);
  return(fileWriter);
}

/**
 * @brief Checks to see if a long num p is prime.
 *
 * @param p - num to be checked
 * @return true
 * @return false
 *
 */
bool prime_test(long p) {
  // Cover simple base cases
  if (p == 2 || p == 3){
    return(true);
  }
  if (p <= 1 || p % 2 == 0 || p % 3 == 0){
    return(false);
  }
  // Your Code Here
  for(int i = 3; i <= sqrt(p); i++){
    if(p % i == 0){
      return(false);
    }
  }
  return(true);
}

/**
 * @brief Euclid's GCD Algorithm
 *
 * @param num Numerator
 * @param den Denominator
 * @return int, Greatest Common Divisor
 *
 */
int gcd(int num, int den) {
  int quot, rem;
  while (den > 0) {
    quot = num / den;
    rem = num % den;
    num = den;
    den = rem;
  }
  return num;
}

/**
 * @brief Prompts user for block size.
 *
 * @param blkSize - input from user for block size
 *
 */
void prompt_user_block(int& blkSize) {
  // Your Code Here
  do{
    cout << "Enter plaintext block size: ";
    cin >> blkSize;
    if(blkSize <= 1){
      cout << endl <<
        "ERROR: block size must be greater than 1!" << endl;
    }
  }while(blkSize <= 1);
}

/**
 * @brief Prompts user for prime num and checks if prime.
 *
 * @param p - num to be checked
 *
 */
void _prompt_user_prime(int& p) {
  // Your Code Here
  bool primeNum = false;
  do{
    cout << "Enter sufficiently large prime number: ";
    cin >> p;
    primeNum = prime_test(p);
    if(primeNum == false){
      cout << "ERROR: " << p << " is not prime!" << endl;
    }
  }while(primeNum == false);
}

/**
 * @brief Prompts user for two prime nums and runs checks.
 *
 * @param p - 1st num provided and checked
 * @param q - 2nd num provided and checked
 * @param b - block size provided earlier
 *
 * Hint: Use the pow function from the math library here
 */
void prompt_user_prime(int& p, int& q, int b) {
  for (;;) {
    _prompt_user_prime(p);
    _prompt_user_prime(q);
    if (p == q) {
      cout << "ERROR: p cannot equal q!" << endl;
      continue;
    } else if ((p*q) < pow(base, b)) {
      cout << "ERROR: p * q must be larger than " << base << "^" << b <<
          "!" << endl;
      continue;
    } else {
      break;
    }
  }
}

/**
 * @brief Prompts user for relative prime, or public key
 *
 * @param e - relative prime and public key
 * @param phi_n - 1st and 2nd prime - 1 multiplied by each other
 */
void prompt_user_relative_prime(long& e, long phi_n) {
  // Your Code Here
  bool primeTest = false;
  do{
    cout << "Enter value that is relative prime to " << phi_n << ": ";
    cin >> e;
    if(e > phi_n){
      cout << "ERROR: value must be less than " << phi_n << endl;
    } else if(e < 2){
      cout << "ERROR: value must be greater than 2" << endl;
    } else if(gcd(e, phi_n) != 1){
      cout << "ERROR: " << e << " is not relatively prime to "
        << phi_n << "!" << endl;
    } else{
      primeTest = true;
    }
  }while(primeTest == false);
}

/**
 * @brief Function to generate all values that are
 * relatively prime to the Euler
 * totient phi(n)
 *
 * @param phi_n Euler totient phi(n) calculated from
 * the prime values p and q
 *
 */
void generate_relative_primes(long phi_n) {
  cout << "\nGenerating all values relatively prime to " << phi_n;

  int SI = 1;
  int versa = phi_n;

  do {
    versa /= 10;
    SI++;
  } while (versa != 0);

  for (int i = 2; i < phi_n; i++) {
    if (gcd(i, phi_n) == 1) {
      cout << setw(SI) << i << ",";
      if (++versa % 10 == 0) cout << endl;
    }
  }
  cout << endl;
}

/**
 * @brief Function to generate the private key given the public key
 * and prime product (p * q) or n
 *
 * @param a Public Key (e)
 * @param n Prime product (p * q)
 * @return long, private key
 *
 * @bug
 *  There are instances where negative private keys are generated
 */
long generate_private_key(long a, long n) {
  long d = 1, d_temp = 0;
  long quotient, versa;
  while (n) {
    quotient = a / n;
    versa = a;
    a = n;
    n = versa - quotient * n;
    versa = d;
    d = d_temp;
    d_temp = versa - quotient * d_temp;
  }
  return d < 0 ? d + n : d;
}

// Place the file handler functions here

/**
 * @brief Function to apply a key to either a
 * piece of cipher text or plain text
 * Thus is the beauty of encryption that
 * the methods of encryption and
 * decryption are identical but with differnt parameters
 *
 * @param key Public or Private Key
 * @param n Prime product (p * q)
 * @param text Message to be encrypted or decrypted
 * @return long, Encoded or Decoded message
 */
long apply_key(long key, long n, long text) {
  long msg = 1;
  while (key--) {
    msg *= text;
    msg %= n;
  }
  return msg;
}

/**
 * @brief This function serves to both encode a plaintext ascii
 * and send that encoding off to the apply_key function for
 * encryption
 *
 * The message to be encrypted exists within a file and must be read
 *
 * For each block the function encrypts it will write that data
 * to an output file separated by newlines
 *
 * @param key Public Key (e)
 * @param n Prime Product (p * q)
 * @param block Amount of characters encoded in each block
 *
 * @details
 * Hint: The given for loop will parse each block of the message
 * Embbed a for loop to implement the series composition
 */
void encrypt_message(long key, long n, int block) {
  int power; // Used to raise a base power
  long cipher = 0; // Used to store the series compound
  string message;

  ifstream input = open_input_file();
  getline(input, message);
  input.close();

  ofstream output = open_output_file();

  for (int i = 0; i < 5; i++) {
    int strBlock[block];
    string tmpMsg;
    cipher = 0;
    for(int i = block - 1; i >= 0; i--){
      tmpMsg.push_back(message[i]);
    }
    for(int i = 0; i < block; i++){
      strBlock[i] = (tmpMsg[i] - 1) % 64;
      cipher += (pow(27, i) * strBlock[i]);
    }
    message = message.substr(block, message.length() - 1);
    output << apply_key(key, n, cipher) << endl;
  }
  output.close();
}

/**
 * @brief This function serves to both decrypt, decode, and then display
 * the original encrypted data
 *
 * The encrypted data was generated by
 * the encrypt_message function and was
 * stored in a file. Each row of the file
 * represents an encrypted block of data
 *
 * @param key Private Key (d)
 * @param n Prime Product (p * q)
 * @param block Amount of characters encoded in each block
 */
void decrypt_message(long key, long n, int block) {
  long cipher;
  int power;
  char letter;

  string message, original;
  ifstream input = open_input_file();

  while (getline(input, message)) {
    cipher = apply_key(key, n, stol(message));
    for (int i = block - 1; i >= 0; i--) {
      power = (int)pow(base, i);

      letter = cipher / power;
      letter = letter != 26 ? letter + 65 : ' ';

      original += letter;
      cipher %= power;
    }
  }
  cout << original << endl;

  input.close();
}

/**
 * @brief Serves to demonstrate the efficacy
 * of all the functions implemented above
 *
 * @param argc Count of command line parameters
 * @param argv Array of command line paramters
 * @return int, Status
 */
int main(int argc, char const* argv[]) {
  int block, p, q;
  long n, phi_n, e, d;

  prompt_user_block(block);

  prompt_user_prime(p, q, block);

  n = p * q;
  phi_n = (p - 1) * (q - 1);

  // REMEMBER: THIS WAS UNCOMMENTED!
  // YOU MAY NEED TO COMMENT THIS OUT
  // AGAIN UPON SUBMISSION!
  // generate_relative_primes(phi_n);

  prompt_user_relative_prime(e, phi_n);

  d = generate_private_key(e, phi_n);

  cout << "Private key = " << d << endl;
  
  cout << "Encrypting Message" << endl;
  encrypt_message(e, n, block);

  cout << "Decrypting Cipher" << endl;
  decrypt_message(d, n, block);


  return 0;
}
