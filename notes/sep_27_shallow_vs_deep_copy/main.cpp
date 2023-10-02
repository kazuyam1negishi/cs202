#include <iostream>
using namespace std;

class Rectangle{
	private:
        int length;
        int * width;
    public:
        Rectangle();
        // Rectangle(int l, int w);
		Rectangle(Rectangle const &); // Copy constructor
        void setRectangle(int l, int w);
        void print() const;
        ~Rectangle();
};

Rectangle::Rectangle(){
	length = 0;
    width = new int;
	* width = 0;
}
/*
Rectangle::Rectangle(int l, int w){
	length = l;
	width = new int;
	* width = w;
}
*/
Rectangle::Rectangle(Rectangle const &obj){
	length=obj.length;
	width=obj.width;
}
void Rectangle::setRectangle(int l, int w){
	length = l;
	* width = w;
}
void Rectangle::print() const{
	cout << "Length: " << length << " Address: " << &length
		<< endl << "Width: " << * width << " Address: " << &width
		<< " Address in width: " << width << endl << endl;
}
Rectangle::~Rectangle(){
	// delete width;
	// width = nullptr;
}

int main(){
	Rectangle rObj;
	rObj.setRectangle(10,15);
	rObj.print();

	// Rectangle rObj2(20, 25);
	// rObj2.print();
	
	// This is a copy constructor.
	// Rectangle rObj3=rObj;
	// This is also one.
	Rectangle rObj3(rObj);
	rObj3.print();

	// Rectangle rObj4;
	// This is an assignment operator.
	// rObj4=rObj2;
	// rObj4.print();
}
