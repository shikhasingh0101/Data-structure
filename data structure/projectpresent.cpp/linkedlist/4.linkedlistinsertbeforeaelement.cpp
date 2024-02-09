#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};
void insertBefore(Node* &head, int element, int value) {
   
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }
    if (head->data == element) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != element) {
        current = current->next;
    }
    if (current->next == nullptr) {
        std::cout << "Element " << element << " not found in the list." << std::endl;
        delete newNode;
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
int main() {
    Node* head = nullptr;
    insertBefore(head, 3, 10);
    insertBefore(head, 3, 20);
    insertBefore(head, 3, 30);

    cout << "Original list: ";
    printList(head);
    insertBefore(head, 20, 25);
    cout << "List after insertion: ";
    printList(head);

    return 0;
}
