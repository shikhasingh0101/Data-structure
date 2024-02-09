#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 6;
    int *ptr1 = &a ;
    int *ptr2 = &b ;
    int sum = (*ptr1)+ (*ptr2);

    cout << sum << endl;   
     (*ptr1++);
     (*ptr2++);
     cout<< *ptr1 <<endl;
     cout<< *ptr2 <<endl;
    
    return 0;
}
