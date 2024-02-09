#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void displayLinkedList(Node* head) {
    
    cout << "Linked List elements: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    Node* head = new Node(11);
    head->next = new Node(22);
    head->next->next = new Node(33);
    head->next->next->next = new Node(44);
    displayLinkedList(head);
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
