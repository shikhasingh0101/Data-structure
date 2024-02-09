#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Array {
    int arr[MAX_SIZE];
    int size;

    Array() : size(0) {}

    void display() {
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i) {
          cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertAtBeginning(int value) {
        if (size == MAX_SIZE) {
           cout << "Array is full. Cannot insert." <<endl;
            return;
        }
        shiftRight();
        arr[0] = value;
        size++;
    }

    void insertAtEnd(int value) {
        if (size == MAX_SIZE) {
            cout << "Array is full. Cannot insert." << endl;
            return;
        }
        arr[size++] = value;
    }

    void insertBefore(int element, int value) {
        int index = findIndex(element);
        if (index == -1) {
            cout << "Element not found. Cannot insert." << endl;
            return;
        }
        shiftRightFrom(index);
        arr[index] = value;
        size++;
    }

    void insertAfter(int element, int value) {
        int index = findIndex(element);
        if (index == -1) {
           cout << "Element not found. Cannot insert." << endl;
            return;
        }
        shiftRightFrom(index + 1);
        arr[index + 1] = value;
        size++;
    }

    void deleteAtBeginning() {
        if (size == 0) {
            cout << "Array is empty. Cannot delete." << endl;
            return;
        }
        shiftLeft();
        size--;
    }

    void deleteAtEnd() {
        if (size == 0) {
           cout << "Array is empty. Cannot delete." <<endl;
            return;
        }
        size--;
    }

    void deleteBefore(int element) {
        int index = findIndex(element);
        if (index <= 0) {
            cout << "No element to delete before. Cannot delete." << endl;
            return;
        }
        shiftLeftFrom(index - 1);
        size--;
    }

    void deleteAfter(int element) {
        int index = findIndex(element);
        if (index == -1 || index == size - 1) {
            cout << "No element to delete after. Cannot delete." << endl;
            return;
        }
        shiftLeftFrom(index);
        size--;
    }

    bool search(int value) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    int count() {
        return size;
    }

private:
    int findIndex(int element) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void shiftRight() {
        for (int i = size; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
    }

    void shiftRightFrom(int index) {
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }
    }

    void shiftLeft() {
        for (int i = 0; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
    }

    void shiftLeftFrom(int index) {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
    }
};

int main() {
    Array arr;
    arr.insertAtEnd(10);
    arr.insertAtEnd(20);
    arr.insertAtEnd(30);
    arr.insertAtEnd(40);
    arr.insertAtEnd(50);

    arr.display();
    arr.insertAtBeginning(5);
    arr.display();
    arr.insertBefore(30, 25);
    arr.display();
    arr.insertAfter(40, 45);
    arr.display();
    arr.deleteAtBeginning();
    arr.display();
    arr.deleteAtEnd();
    arr.display();
    arr.deleteBefore(30);
    arr.display();
    arr.deleteAfter(20);
    arr.display();
    cout << "Search for 25: " << (arr.search(25) ? "Found" : "Not found") <<endl;
    cout << "Search for 35: " << (arr.search(45) ? "Found" : "Not found") << endl;
    cout << "Number of elements: " << arr.count() << endl;

    return 0;
}
