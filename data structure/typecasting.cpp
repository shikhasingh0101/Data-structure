

#include<iostream>
using namespace std;

int main() {
    char* ptr;         
    char a = 'I';         
    ptr = &a;          

    cout << a << endl; 
    
    //cout << *ptr<< endl;          
    cout << *(char*)ptr << endl; 

    return 0;
}
