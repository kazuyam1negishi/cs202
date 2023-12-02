#include <iostream>
using namespace std;

// Add functionality to check
// for out of bounds pushes and peeks.

class stack{
    private:
        const int SIZE = 5;
        int top;
        int arr[5];
    public:
        stack();
        bool isEmpty();
        bool isFull();
        void push(int);
        void pop();
        int peek(int);
        void change(int, int);
        void print();
        void swap(int pos1, int pos2);

};

stack::stack(){
    top = -1;
    for(int i = 0; i < SIZE; i++){
        arr[i] = 0;
    }
}

bool stack::isEmpty(){
    if(top == -1){
        return(true);
    }
    return(false);
}

bool stack::isFull(){
    if(top == SIZE - 1){
        return(true);
    }
    return(false);
}

void stack::push(int value){
    if(isFull() == true){
        return;
    }
    top++;
    arr[top] = value;
}

void stack::pop(){
    if(isEmpty() == true){
        return;
    }
    cout << arr[top] << endl;
    arr[top] = 0;
    top--;
}

int stack::peek(int position){
    return(arr[position]);
}

void stack::change(int value, int position){
    arr[position] = value;
}

void stack::print(){
    for(int i = 0; i < top + 1; i++){
        cout << arr[i] << endl;
    }
}

int main(){
    stack iQ;
    iQ.push(6);
    iQ.push(8);
    iQ.push(7);
    iQ.push(0);
    iQ.change(4, 3);
    iQ.print();
    return(0);
}