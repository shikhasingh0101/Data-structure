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

int countElements(const Array& arr) {
    return arr.size;
}

int main() {
    Array arr(6);
    arr.data[0] = 11;
    arr.data[1] = 22;
    arr.data[2] = 33;
    arr.data[3] = 44;
    arr.data[4] = 55;
    arr.data[5] = 66;

    int numElements = countElements(arr);
    cout << "Number of elements in the array: " << numElements << endl;

    return 0;
}
