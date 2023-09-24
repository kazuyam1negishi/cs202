#include <iostream>
using namespace std;

int main(){
    int x = 20;
    int * ptr = nullptr;
    ptr = &x;

    cout << "X's address: " << ptr << endl;

    int * ptr2 = new int;
    * ptr2 = 45;

    cout << "ptr2's address: " << & ptr2 << endl;
    cout << "ptr2's reference: " << * ptr2 << endl;

    // deletes new int
    delete ptr2;
    // removes address
    ptr2 = nullptr;
    // now just don't reference ptr2 again
    // do both to avoid a memory leak and
    // seg fault/core dump

    int * arr = new int[5];

    for(int i = 0; i < 5; i++){
        arr[i] = rand() % 20;
    }
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // use this if the array is multidimensional
    //for(int i = 0; i < 5; i++){
    //    delete arr[i];
    //}
    delete [] arr;
    arr = nullptr;

    return(0);
}