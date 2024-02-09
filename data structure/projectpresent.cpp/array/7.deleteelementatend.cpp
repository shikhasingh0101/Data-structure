#include <iostream>
using namespace std;

struct Array {
    int* data;
    int size;

    Array(int s) : size(s) {
        data = new int[size];
    }

    ~Array() {
        delete[] data;
    }
};

void displayArray(const Array& arr) {
    cout << "Array elements: ";
    for (int i = 0; i < arr.size; ++i) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

void deleteAtEnd(Array& arr) {
    if (arr.size == 0) {
        cout << "Array is empty\n";
        return;
    }

    arr.size--;
}

int main() {
    Array arr(6);
    arr.data[0] = 11;
    arr.data[1] = 22;
    arr.data[2] = 33;
    arr.data[3] = 44;
    arr.data[4] = 55;
    arr.data[5] = 66;

    displayArray(arr);

    
    deleteAtEnd(arr);
    displayArray(arr);

    return 0;
}
