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

void deleteAtIndex(Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cout << "Invalid index\n";
        return;
    }

    for (int i = index; i < arr.size - 1; ++i) {
        arr.data[i] = arr.data[i + 1];
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

    deleteAtIndex(arr, 2);
    displayArray(arr);

    return 0;
}
