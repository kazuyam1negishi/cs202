#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

class queueLL{
    private:
        Node * head;
        Node * tail;
    public:
        queueLL();
        ~queueLL();
        bool isEmpty();
        void enqueue(int value);
        void dequeue();
        int nodeCount();
        void showFront();
        void showEnd();
        void print();
        void printRevRec(Node * ptr); // Reverse using recursion
};

queueLL::queueLL(){
    head = nullptr;
    tail = nullptr;
}

queueLL::~queueLL(){
    if(head == nullptr && tail == nullptr){
        return;
    } else {
        while(head != nullptr){
            Node * temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
        head = nullptr;
    }
}

bool queueLL::isEmpty(){
    if(head == nullptr && tail == nullptr){
        return(true);
    }
    return(false);
}

void queueLL::enqueue(int value){
    Node * temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    if(head == nullptr && tail == nullptr){
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
        // Do this to enqueue at tail instead of head
        // temp->next = tail;
        // tail = temp;
    }
}

void queueLL::dequeue(){
    if(head == nullptr && tail == nullptr){
        return;
    } else {
        Node * temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
}

int queueLL::nodeCount(){
    int count = 0;
    if(head == nullptr && tail == nullptr){
        return(count);
    } else {
        Node * ptr = head;
        while(ptr != nullptr){
            count++;
            ptr = ptr->next;
        }
    }
    return(count);
}

void queueLL::print(){
    if(head == nullptr && tail == nullptr){
        return;
    } else {
        Node * ptr = head;
        while(ptr != nullptr){
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}

void queueLL::printRevRec(Node * ptr){
    if(head == nullptr && tail == nullptr){
        return;
    } else if(ptr == nullptr){
        ptr = head;
    } else {
        printRevRec(ptr->next);
    }
    cout << ptr->data << endl;
}

int main(){
    queueLL qObj;
    // Node * ptr = nullptr;
    qObj.enqueue(5);
    qObj.enqueue(10);
    qObj.enqueue(15);
    qObj.enqueue(20);
    qObj.print();
    cout << endl;
    // qObj.dequeue();
    // qObj.print();
    cout << endl;
    // qObj.printRevRec(ptr);
    cout << qObj.nodeCount();
    cout << endl;
    return(0);
}