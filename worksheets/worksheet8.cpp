#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * prev;
    Node * next;
};

class stackLL{
    private:
        int top;
        Node * head;
        Node * tail;
    public:
        stackLL(){
            top = -1;
        };
        ~stackLL(){
            Node * ptr = head;
            while(head != nullptr){
                ptr = head;
                head = head->next;
                delete ptr;
            }
        };
        bool isEmpty(){
            if(top == -1){
                cout << "Empty\n";
                return(true);
            } else {
                cout << "Not empty\n";
                return(false);
            }
        };
        void insertAtTop(int value){
            Node * temp = new Node;
            temp->data = value;
            temp->prev = nullptr;
            temp->next = nullptr;
            if(isEmpty() == true){
                head = temp;
                tail = temp;
                top++;
            } else {
                temp->next = head;
                head->prev = temp;
                head = temp;
                top++;
            }
        };
        void removeAtTop(){
            if(isEmpty() == true){
                return;
            } else {
                Node * delPtr = tail;
                Node * curr = tail;
                while(curr->prev != nullptr){
                    delPtr = curr;
                    curr = curr->prev;
                }
                head = curr;
                delPtr->prev = nullptr;
                curr->prev = nullptr;
                delete delPtr;
                top--;
            }
        };
        int nodeCount(){
            if(isEmpty() == true){
                return(0);
            } else {
                return(top + 1);
            }
        };
        void printList(){
            if(isEmpty() == true){
                return;
            } else {
                int count;
                Node * ptr = head;
                for(int i = 0; i < top + 1; i++){
                    cout << ptr->data << endl;
                    if(ptr->next != nullptr){
                        ptr = ptr->next;
                    }
                }
            }
        };
        void printListRev(){
            if(isEmpty() == true){
                return;
            } else {
                Node * ptr = tail;
                for(int i = top + 1; i > 0; i--){
                    cout << ptr->data << endl;
                    ptr = ptr->prev;
                }
            }
        };
        void printListRevRec(int var){
            if(isEmpty() == true){
                return;
            } else {
                Node * ptr = tail;
                for(int i = 0; i < top - var; i++){
                    ptr = ptr->prev;
                }
                cout << ptr->data << endl;
                printListRevRec(var - 1);
            }
        };
        void printTop(){
            if(isEmpty() == true){
                return;
            } else {
                cout << head->data << endl;
            }
        };
};

int main(){
    stackLL tester;
    int input = 0;
    int val = 0;
    while(input != 9){
        cout << "1. isEmpty()\n"
            << "2. insertAtTop()\n"
            << "3. removeAtTop()\n"
            << "4. nodeCount()\n"
            << "5. printList()\n"
            << "6. printListReverse()\n"
            << "7. printListReverseRecursive()\n"
            << "8. printTop()\n"
            << "9. Exit\n";
        cin >> input;
        switch(input){
            case 1:
                tester.isEmpty();
                break;
            case 2:
                cout << "What int value?";
                cin >> val;
                tester.insertAtTop(val);
                break;
            case 3:
                tester.removeAtTop();
                break;
            case 4:
                cout << tester.nodeCount();
                break;
            case 5:
                tester.printList();
                break;
            case 6:
                tester.printListRev();
                break;
            case 7:
                tester.printListRevRec(tester.nodeCount()-1);
                break;
            case 8:
                tester.printTop();
                break;
            case 9:
                exit(0);
            default:
                break;
        }
    }
}