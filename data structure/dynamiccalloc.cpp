//DYANAMIC ARRAY
#include <iostream>
#include <cstdlib>  
using namespace std;

int main() {
    int* arr = (int*)calloc(10, sizeof(int));
    *arr = 10;

    cout << *arr << endl;

    free(arr);

    return 0;
}