#include<iostream>
using namespace std;

int sumofNaturalNumbers(int n);

int main(){
    int number = 0;
    cout << "Enter number: ";
    cin >> number;
    while(number < 0){
    try{
        cout << "Enter number: ";
        cin >> number;
        if(number < 0){
            cout << "The number is negative" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            throw 5;
        }
    }
    catch(int x){
        cout << "You must enter only positive: " << endl;
        //return 0;
    }
    }
    cout << "Result: " << sumofNaturalNumbers(number) << endl;
}

int sumofNaturalNumbers(int n){
    if(n == 0){
        return(0);
    }
    return (n + sumofNaturalNumbers(n-1));
}