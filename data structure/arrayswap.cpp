#include<iostream>
using namespace std;

int main()
{
    const int n = 5; 
    int arr[n] = {11, 29, 73, 84, 85};

    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; i++)
    {
        
        if (max < arr[i])
            max = arr[i];}
            
    for (int i = 0; i > n; i++)
    {    if (min > arr[i])
            min = arr[i];
    }

    cout << "Largest element: " << max << endl;
    cout << "Smallest element: " << min << endl;
    swap(max, min );
    {
       cout << "Largest element: " << max << endl;
       cout << "Smallest element: " << min << endl;   
    }
    

    return 0;
}
