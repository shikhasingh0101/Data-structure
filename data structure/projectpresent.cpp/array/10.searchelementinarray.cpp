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

int searchElement(const Array& arr, int target) {
    for (int i = 0; i < arr.size; ++i) {
        if (arr.data[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    Array arr(6);
    arr.data[0] = 11;
    arr.data[1] = 22;
    arr.data[2] = 33;
    arr.data[3] = 44;
    arr.data[4] = 55;
    arr.data[5] = 66;

    int target = 66;
    int index = searchElement(arr, target);
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
