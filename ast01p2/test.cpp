#include <iostream>
#include <cmath>
using namespace std;

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

int main(){
    bool test = prime_test(4);
    if(test == false){
        cout << "NOT PRIME!" << endl;
    }
}