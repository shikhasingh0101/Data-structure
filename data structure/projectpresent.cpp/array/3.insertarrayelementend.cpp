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

void insertAtEnd(Array& arr, int element) {
    int* newData = new int[arr.size + 1];
    for (int i = 0; i < arr.size; ++i) {
        newData[i] = arr.data[i];
    }
    newData[arr.size] = element;
    delete[] arr.data;
    arr.data = newData;
    arr.size++;
}

int main() {
    Array arr(5);
    arr.data[0] = 11;
    arr.data[1] = 22;
    arr.data[2] = 33;
    arr.data[3] = 44;
    arr.data[4] = 55;

    displayArray(arr);

    insertAtEnd(arr, 99);
    displayArray(arr);

    return 0;
}
