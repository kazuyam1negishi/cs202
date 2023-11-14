#include <iostream>
#include <string>
using namespace std;

template<class type>
class findLarger {
    private:
        type a;
        type b;
    public:
        findLarger();
        findLarger(type, type);
        type calculateLargest(type, type);
};

int main(){
    string strOne = "Computer";
    string strTwo = "Engineer";
    findLarger testOne(2, 5);
    findLarger testTwo(98.7, 24.5);
    findLarger testThree(strOne, strTwo); 
    testOne.calculateLargest(2, 5);
    testTwo.calculateLargest(98.7, 24.5);
    testThree.calculateLargest(strOne, strTwo);
    return(0);
}

template<class type>
findLarger<type>::findLarger(){
    a = 0;
    b = 0;
};

template<class type>
findLarger<type>::findLarger(type varOne, type varTwo){
    a = varOne;
    b = varTwo;
};

template<class type>
type findLarger<type>::calculateLargest(type varOne, type varTwo){
    cout << "Largest between " << a << " and "
        << b << ": ";
    if(varOne > varTwo){
        cout << varOne << "\n";
        return(varOne);
    } else {
        cout << varTwo << "\n";
        return(varTwo);
    }
    return(a);
};