#include <iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int * width;
    public:
        Rectangle();
        Rectangle(int, int);
        void print() const;
        Rectangle& operator=(Rectangle const &);
        Rectangle operator+(Rectangle const &);
        Rectangle operator*(Rectangle const &);
        bool operator==(Rectangle const &);
        bool operator!=(Rectangle const &);
        void operator++();
        void operator++(int);
        friend istream& operator>>(istream &, Rectangle &);
        ~Rectangle();
};

int main(){
    Rectangle rectOne(5, 7);
    Rectangle rectTwo(12, 15);
    Rectangle rectThree(12, 15);

    // Testing !=
    if(rectOne != rectTwo){
        cout << "rectOne and rectTwo are not equal!\n";
    } else {
        cout << "rectOne and rectTwo are equal!\n";
    }
    // Testing ==
    if(rectThree == rectTwo){
        cout << "rectThree and rectTwo are equal!\n";
    } else {
        cout << "rectThree and rectTwo are not equal!\n";
    }

    // Testing >>
    Rectangle rectFour;
    cin >> rectFour;
    rectFour.print();

    // Testing ++ operator
    Rectangle rectFive;
    ++rectFive;
    rectFive.print();
    // Testing post increment one
    rectFive++;
    rectFive.print();

    // Testing + operator
    Rectangle rectSix = rectOne + rectTwo;
    rectSix.print();
    // Testing * operator
    Rectangle rectSeven = rectTwo * rectThree;
    rectSeven.print();
}

Rectangle::Rectangle(){
    length = 0;
    width = new int;
    * width = 0;
}
Rectangle::Rectangle(int l, int w){
    length = l;
    width = new int;
    * width = w;
}
void Rectangle::print() const{
    cout << "Length: " << length << " Width: " << *width << endl;
}
Rectangle::~Rectangle(){
    delete width;
}
Rectangle& Rectangle::operator=(Rectangle const &rObj){
    length = rObj.length;
    *(width) = *(rObj.width);
    return *this;
};
Rectangle Rectangle::operator+(Rectangle const &rObj){
    Rectangle temp;
    temp.length = this->length + rObj.length;
    *temp.width = *(this->width) + *(rObj.width);
    return temp;
}
Rectangle Rectangle::operator*(Rectangle const &rObj){
    Rectangle temp;
    temp.length = this->length * rObj.length;
    *temp.width = (*width) * (*rObj.width);
    return temp;
}
bool Rectangle::operator==(Rectangle const &rObj){
    return(this->length == rObj.length && *(this->width) == *(rObj.width));
}
bool Rectangle::operator!=(Rectangle const &rObj){
    return(this->length != rObj.length && *(this->width) != *(rObj.width));
}
void Rectangle::operator++(){
    ++length;
    ++*(this->width);
}
void Rectangle::operator++(int n){
    this->length++;
    ++*(this->width);
}
istream & operator>>(istream &strObj, Rectangle &rObj){
    int len = 0;
    cout << "Enter length: ";
    strObj >> len;
    rObj.length = len;
    cout << "Enter width: ";
    strObj >> *rObj.width;

    return strObj;
}