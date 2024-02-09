#include<iostream>
using namespace std;

int main()
{
    const int n = 5; 
    int arr[n] = {11, 29, 73, 84, 85};
    int arr1[n] = {22,23,24,25,26};
    int arr2[n] = {38,39,40,41,42};
    int* ptrarray[3] = {arr, arr1, arr2};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cout << *(ptrarray[i] + j) << " ";
        }
        cout << endl;
    }
    return 0;
}
