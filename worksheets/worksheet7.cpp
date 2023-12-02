#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * prev;
    Node * next;
};

class doublyLL{
    private:
        Node * head;
        Node * tail;
    public:
        doublyLL();
        ~doublyLL();
        void insertAtHead(int);
        void insertAtTail(int);
        void deleteAtHead();
        void deleteAtTail();
        void print();
        void printReverse();
};

// Finished!
doublyLL::doublyLL(){
    head = nullptr;
    tail = nullptr;
}

// Finished!
doublyLL::~doublyLL(){
    if(head == nullptr && tail == nullptr){
        return;
    } else {
        Node * ptr = head;
        while(head != nullptr){
            ptr = head;
            head = head->next;
            delete ptr;
        }
        head = nullptr;
    }
}

// Finished!
void doublyLL::insertAtHead(int value){
    Node * temp = new Node;
    temp->data = value;
    temp->prev = nullptr;
    temp->next = nullptr;
    if(head == nullptr && tail == nullptr){
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Finished!
void doublyLL::insertAtTail(int value){
    Node * temp = new Node;
    temp->data = value;
    temp->prev = nullptr;
    temp->next = nullptr;
    if(head == nullptr && tail == nullptr){
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Finished!
void doublyLL::deleteAtHead(){
    if(head == nullptr && tail == nullptr){
        return;
    } else {
        Node * ptr = head;
        head = head->next;
        delete ptr;
    }
}

// Finished!
void doublyLL::deleteAtTail(){
    if(head == nullptr && tail == nullptr){
        return;
    } else {
        Node * ptr = head;
        Node * last = head;
        while(ptr->next != nullptr){
            last = ptr;
            ptr = ptr->next;
        }
        tail = ptr;
        last->next = nullptr;
        ptr->prev = nullptr;
        delete ptr;
    }
}

// Finished!
void doublyLL::print(){
    if(head == nullptr && tail == nullptr){
        cout << "Empty list!\n";
    } else {
        Node * ptr = head;
        while(ptr != nullptr){
            cout << ptr->data << endl;
            ptr = ptr->next;
        };
    }
}

// Finished!
// Personal achievement
// Get a function to work first time!
void doublyLL::printReverse(){
    if(head == nullptr && tail == nullptr){
        cout << "Empty list!\n";
    } else {
        Node * ptr = tail;
        while(ptr != nullptr){
            cout << ptr->data << endl;
            ptr = ptr->prev;
        };
    }
}

int main(){
    doublyLL test;
    // 5 10 15 20
    test.insertAtHead(10);
    test.insertAtHead(5);
    test.insertAtTail(15);
    test.insertAtTail(20);
    // 5 10 15 20
    test.print();
    cout << endl;
    // 20 15 10 5
    test.printReverse();
    cout << endl;
    // 10 15
    test.deleteAtHead();
    test.deleteAtTail();
    test.print();
    return(0);
}