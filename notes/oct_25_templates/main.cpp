// Note: templates do not affect friend functions
// unless the template is redeclared in the class.

#include <iostream>
using namespace std;

// template<class T>
// void printData(T);
// void swapData(T, T);
template<typename T, typename U>
// void multiply(T, U);
class Rectangle{
    private:
        T length;
        U width;
    public:
        Rectangle(){
            length = 0;
            width = 0;
        }
        Rectangle(const T&, const U&);
        void printData();
        bool checkEqual();
};
int main(){
    //printData(12);
    //printData(12.99);
    //printData('A');
    //printData("Pen");
    return(0);
};

// template<class T>
/*
void printData(T x){
    cout << x << endl;
}
void swapData(T x, T y){
    T temp;
    temp = x;
    x = y;
    y = temp;
    cout << x << ", " << y << endl;
}
*/

// template<typename T, typename U>
/*
void multiply(T x, U y){
    cout << x * y << endl;
}
*/
template<typename T, typename U>
Rectangle<T, U>::Rectangle(const T &l, const U &w){
    length = l;
    width = w;
}

template<typename T, typename U>
void Rectangle<T, U>::printData(){

}
template<typename T, typename U>
bool Rectangle<T, U>::checkEqual(){

}