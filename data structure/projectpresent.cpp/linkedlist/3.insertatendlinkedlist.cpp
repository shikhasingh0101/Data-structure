#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertExtraElementAtEnd(Node*& head, int extraValue) {

    Node* extraNode = new Node(extraValue);

   
    if (head == nullptr) {
        head = extraNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    
    current->next = extraNode;
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

    insertExtraElementAtEnd(head, 11);
    insertExtraElementAtEnd(head, 22);
    insertExtraElementAtEnd(head, 33);
    insertExtraElementAtEnd(head, 44);

    displayLinkedList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    

    return 0;
}

