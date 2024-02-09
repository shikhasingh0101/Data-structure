#include<iostream>
using namespace std;

const int MAX_SIZE = 100; 

int n;
int arr[MAX_SIZE];

void insertAtBeginning(int val)
{
    if (n >= MAX_SIZE)
    {
        cout << "Array is full, cannot insert more elements.\n";
        return;
    }
    
    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = val;
    n++; 
    cout << "Element inserted at the beginning: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ",";
    }
    cout << endl;
}

void insertAtEnd(int val)
{
    if (n >= MAX_SIZE)
    {
        cout << "Array is full, cannot insert more elements.\n";
        return;
    }
    
    arr[n] = val;
    n++; 
    cout << "Element inserted at the end: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ",";
    }
    cout << endl;
}

void insertBeforeElement(int val, int element)
{
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Element not found in the array.\n";
        return;
    }

    insertAtBeginning(val);
    for (int i = n - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = val;
    cout << "Element inserted before specified element: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ",";
    }
    cout << endl;
}

void insertAfterElement(int val, int element)
{
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Element not found in the array.\n";
        return;
    }

    for (int i = n; i > index + 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index + 1] = val;
    n++; 
    cout << "Element inserted after specified element: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ",";
    }
    cout << endl;
}

void deleteAtBeginning()
{
    if (n == 0)
    {
        cout << "Array is empty, cannot delete.\n";
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted from the beginning: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ",";
    }
    cout << endl;
}

void deleteAtEnd()
{
    if (n == 0)
    {
        cout << "Array is empty, cannot delete.\n";
        return;
    }

    n--; 
    cout << "Element deleted from the end: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ",";
    }
    cout << endl;
}

void deleteBeforeElement(int element)
{
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            index = i;
            break;
        }
    }

    if (index <= 0)
    {
        cout << "No element to delete before.\n";
        return;
    }

    for (int i = index - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted before specified element: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ",";
    }
    cout << endl;
}

void deleteAfterElement(int element)
{
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            index = i;
            break;
        }
    }

    if (index == -1 || index == n - 1)
    {
        cout << "No element to delete after.\n";
        return;
    }

    for (int i = index + 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--; 
    cout << "Element deleted after specified element: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ",";
    }
    cout << endl;
}

int searchElement(int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

void displayArray()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter the size of the array: ";
    cin >> n;
    
    cout << "Enter " << n << " elements for the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int newValue;
    cout << "Enter the value to insert at the beginning: ";
    cin >> newValue;
    insertAtBeginning(newValue);

    cout << "Enter the value to insert at the end: ";
    cin >> newValue;
    insertAtEnd(newValue);

    int element, beforeValue;
    cout << "Enter the element before which you want to insert: ";
    cin >> element;
    cout << "Enter the value to insert before " << element << ": ";
    cin >> beforeValue;
    insertBeforeElement(beforeValue, element);

    int afterValue;
    cout << "Enter the element after which you want to insert: ";
    cin >> element;
    cout << "Enter the value to insert after " << element << ": ";
    cin >> afterValue;
    insertAfterElement(afterValue, element);

    deleteAtBeginning();
    deleteAtEnd();
    cout << "Enter the element before which you want to delete: ";
    cin >> element;
    deleteBeforeElement(element);
    cout << "Enter the element after which you want to delete: ";
    cin >> element;
    deleteAfterElement(element);

    int searchValue;
    cout << "Enter the value to search: ";
    cin >> searchValue;
    int index = searchElement(searchValue);
    if (index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else
    {
        cout << "Element not found in the array.\n";
    }

    cout << "Array after all operations: ";
    displayArray();

    cout << "Number of elements in the array: " << n << endl;

    return 0;
}
