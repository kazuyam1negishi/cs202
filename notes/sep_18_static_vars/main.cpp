#include <iostream>
using namespace std;

class Shape{
    private:
        int length;
        // static variables will apply to all
        // objects of this same class.
        static int width;
    public:
        Shape(int l = 0);
        static int count;
        void setLength(int l);
        static int setWidth();
        void printData();
};

int main(){
    Shape shape1(8);
    Shape shape2;
    shape1.printData();
    shape2.printData();
    return(0);
}

Shape::Shape(int l){
    length = l;
};
void Shape::setLength(int l){
    length = l;
}
int Shape::setWidth(){
    cout << "Enter width: ";
    cin >> width;
    return(width);
}
void Shape::printData(){
    cout << "L: " << length << endl
        << "W: " << width << endl
        << "C: " << count << endl;
}