#include <iostream>
using namespace std;

// insert at head stuffs
// temp->next = head;
// head = temp;

struct Node{
    int data;
    Node * next;
};

class singularLL{
    private:
        Node * head;
        Node * tail;
    public:
        singularLL();
        void insertAtHead(int);
        void insertAtTail(int);
        void insertAtPosition(int, int); //
        void deleteAtHead(); //
        void deleteAtTail();
        void deleteAtPosition(int);
        void printSLL();
        ~singularLL();
};

singularLL::singularLL(){
    head = nullptr;
    tail = nullptr;
};

singularLL::~singularLL(){
    if(head == nullptr && tail == nullptr){
        cout << "Empty list!\n";
        return;
    } else {
        Node * ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr->next;
            delete head;
            head = nullptr;
            head = ptr;
        }
        delete head;
        head = nullptr;
        ptr = nullptr;
    }
}

void singularLL::insertAtHead(int value){
    Node * temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    // Checks if both are nullptr,
    // as this will be the case with
    // an empty linked list.
    if(head == nullptr && tail == nullptr){
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
};

void singularLL::insertAtTail(int value){
    Node * temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    if(head == nullptr && tail == nullptr){
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void singularLL::insertAtPosition(int value, int position){
    int pos = 1;
    Node * temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    Node * ptr = head;

    if(position == 0){
        insertAtHead(value);
    } else {
        while(pos != position && ptr->next != nullptr){
            ptr = ptr->next;
            pos++;
            if(pos == position){
                temp->next = ptr->next;
                ptr->next = temp;
            } else {
                delete temp;
                cout << "Wrong position selected!\n";
                return;
            }
        }
    }
}

void singularLL::deleteAtHead(){
    if(head == nullptr && tail == nullptr){
        cout << "Empty list!\n";
    } else {
        Node * ptr = head;
        head = head->next;
        delete ptr;
    }
}

void singularLL::deleteAtTail(){
    if(head == nullptr && tail == nullptr){
        cout << "Empty list!\n";
    } else {
        Node * ptr = head;
        Node * last = nullptr;
        while(ptr->next != nullptr){
            last = ptr;
            ptr = ptr->next;
        }
        last->next = nullptr;
        delete ptr;
    }
}

void singularLL::deleteAtPosition(int position){
    
}

void singularLL::printSLL(){
    if(head == nullptr && tail == nullptr){
        cout << "Empty list!\n";
    } else {
        Node * ptr = head;
        while(ptr != nullptr){
            cout << ptr->data << endl;
            ptr = ptr->next;
        };
    }
};

int main(){
    singularLL teufort;
    // 7 5 12
    teufort.insertAtHead(5);
    teufort.insertAtHead(7);
    teufort.insertAtTail(12);
    teufort.printSLL();
    cout << "\n";
    // 5 12
    teufort.deleteAtHead();
    teufort.printSLL();
    cout << "\n";
    // 7 5 12
    teufort.insertAtHead(7);
    teufort.printSLL();
    cout << "\n";
    // 7 5
    teufort.deleteAtTail();
    teufort.printSLL();
    cout << "\n";
    // 7 5 12
    teufort.insertAtPosition(12, 2);
    teufort.printSLL();
    cout << "\n";
    return(0);
}