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
		void changeToNegative(); //unary operator
		Rectangle operator-(Rectangle); // binary operator
		Rectangle &operator=(Rectangle const &); // assignment operator
		bool operator<(Rectangle const &); // relational operator
		friend bool operator>(Rectangle const &, Rectangle const &);
		friend ostream& operator<<(ostream&, Rectangle const &);
        ~Rectangle();
};

Rectangle::Rectangle(){
	length = 0;
    width = new int;
	* width = 0;
}
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
void Rectangle::changeToNegative(){
	length = -length;
	* width = -* width;
}
Rectangle Rectangle::operator-(Rectangle rObj){
	Rectangle temp;
	length = -length;
	* width = -* width;
	return(temp);
}
Rectangle &Rectangle::operator=(Rectangle const &rObj){
	length = rObj.length;
	width = rObj.width;
	return *this;
};
bool Rectangle::operator<(Rectangle const &rObj){
	return(length < rObj.length && *width < *(rObj.width));
};
bool operator>(Rectangle const &rObjOne, Rectangle const &rObjTwo){
	return(rObjOne.length>rObjTwo.length && *rObjOne.width>*rObjTwo.width);
};
ostream & operator<<(ostream &ostrObj, Rectangle const &rObj){
	ostrObj << "Length: " << rObj.length << "\n"
		<< "Width: " << *rObj.width << "\n";
	return(ostrObj);
};

int main(){
	Rectangle rObj1;
	rObj1.setRectangle(10,15);
	rObj1.changeToNegative();
	rObj1.print();

	Rectangle rObj2;
	rObj2.setRectangle(20, 25);
	rObj2.print();
	
	Rectangle rObj3(rObj1);
	rObj3.print();
	
	if(rObj1<rObj2){
		cout << "rObj1 is smaller!\n";
	} else{
		cout << "rObj1 is bigger!\n";
	}
	if(rObj1>rObj2){
		cout << "rObj2 is smaller!\n";
	} else{
		cout << "rObj2 is bigger!\n";
	}
	cout << rObj1;
}