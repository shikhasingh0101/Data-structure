
#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

int main() {
    int NUM = 20;  

    struct node* start = nullptr;
    struct node* n1 = new node;
    n1->data = 10;
    n1->next = nullptr;
    start = n1;

    struct node* n2 = new node;
    n2->data = 20;
    n2->next = nullptr;
    n1->next = n2;

    struct node* n3 = new node;
    n3->data = 30;
    n3->next = nullptr;
    n2->next = n3;

    struct node* n4 = new node;
    n4->data = 40;
    n4->next = nullptr;
    n3->next = n4;

    struct node* preptr = nullptr;
    struct node* ptr = start;

    while (ptr != nullptr && ptr->data != NUM) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr != nullptr) {
        
        if (preptr == nullptr) {
           
            start = ptr->next;
        } else {
            preptr->next = ptr->next;
        }

       
        delete ptr;

        ptr = start;
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    } else {
        cout << "Node with value " << NUM << " not found." << endl;
    }

    return 0;
}
