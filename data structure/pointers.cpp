
#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int *ptr;
    ptr = &a;
    //*ptr = 7;

    cout << a << endl;   
    cout << *ptr << endl; 
    cout<<sizeof(a);
    return 0;
}
