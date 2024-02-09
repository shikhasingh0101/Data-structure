#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    
    Node(int value) : data(value), next(nullptr) {}
};

void insertAtBeginning(Node*& head, int value) {
  
    Node* newNode = new Node(value);
   
    newNode->next = head;
   
    head = newNode;
}

void displayLinkedList(Node* head) {
    
    cout << "Linked List elements: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    Node* head = nullptr;

    insertAtBeginning(head, 44);
    insertAtBeginning(head, 33);
    insertAtBeginning(head, 22);

    displayLinkedList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
