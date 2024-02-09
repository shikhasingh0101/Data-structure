#include<iostream>
using namespace std;

struct node {
    int info;
    struct node* link;
};

int main() {
   
    struct node* start = nullptr;

    node *n1= new node;
    n1->info=30;
    n1->link=NULL;
   
    start= n1;
    node *ptr=start;
    int count= 0;
    
     while (ptr != nullptr) {
        count++; 
        ptr = ptr->link;
        cout<<count;
    }




    return 0;
}
