#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* start = NULL; 

 
    Node* n1 = new Node;
    n1->data = 30;
    n1->next = NULL;

    start = n1;

    return 0;
}
