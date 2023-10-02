#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    /*
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
    */

    // Double pointer syntax and example
    /*
    int x = 20;
    int * ptrOne = &x;
    cout << "Address of x: " << &x << endl;
    cout << "Address of ptrOne: " << &ptrOne << endl;
    cout << "Address stored in ptrOne: " << ptrOne << endl;
    cout << "Value of x: " << *ptrOne << endl << endl;
    int ** ptrTwo = &ptrOne;
    cout << "Address of ptrOne: " << &ptrOne << endl;
    cout << "Address of ptrTwo: " << &ptrTwo << endl;
    cout << "Address stored in ptrTwo: " << *ptrTwo << endl;
    cout << "Value of x: " << **ptrTwo << endl << endl;
    int *** ptrThree = &ptrTwo;
    cout << "Address of ptrTwo: " << &ptrTwo << endl;
    cout << "Address of ptrThree: " << &ptrThree << endl;
    cout << "Address stored in ptrThree: " << **ptrThree << endl;
    cout << "Value of x: " << ***ptrThree << endl;
    */

    // Dynamic 2D array and dynamic allocation
    int rows, columns = 0;
    int ** matrix;

    cout << "Enter rows and columns: " << endl;
    cin >> rows >> columns;

    // Dynamic 2D array allocation
    // new keyword initializes variables
    // on the heap, as opposed to the stack,
    // where the rest of your variables live.
    matrix = new int * [rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new int [columns];
    }
    // Dynamic 2D array value assignment
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = rand() % 55;
        }
    }
    // Visualization of 2D array
    /*
    matrix = int * rows;
    [0]
    [1]
    [2]

    matrix[i] = int columns
    [0][0] [0][1] [0][2]
    [1][0] [1][1] [1][2]
    [2][0] [2][1] [2][2]
    */
    // Print out array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << setw(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // Delete arrays completely
    for(int i = 0; i < rows; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
    matrix = nullptr;
}