#include <iostream>
using namespace std;

template <typename T>
class MyVector {
    T* arr;       // dynamic array
    int capacity; // total allocated size
    int current;  // current number of elements

public:
    // Constructor
    MyVector() {
        capacity = 2;
        current = 0;
        arr = new T[capacity];
    }

    // Insert element at end
    void insert(T value) {
        if (current == capacity) {
            // Double the capacity
            int newCap = capacity * 2;
            T* temp = new T[newCap];

            // Copy old elements
            for (int i = 0; i < current; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;  // free old memory
            arr = temp;    // point to new array
            capacity = newCap;
        }

        arr[current] = value;
        current++;
    }

    // Remove element at given index
    void removeAt(int index) {
        if (index < 0 || index >= current) {
            cout << "Invalid index\n";
            return;
        }

        for (int i = index; i < current - 1; i++) {
            arr[i] = arr[i + 1];
        }

        current--;
    }

    // Search value and return index
    int search(T value) {
        for (int i = 0; i < current; i++) {
            if (arr[i] == value)
                return i;
        }
        return -1; // not found
    }

    // Display all elements
    void display() {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Return size
    int size() {
        return current;
    }

    // Destructor
    ~MyVector() {
        delete[] arr;
    }
};

int main() {
    MyVector<int> v;

    v.insert(10);
    v.insert(20);
    v.insert(30);

    cout << "Vector: ";
    v.display();

    cout << "Index of 20: " << v.search(20) << endl;

    v.removeAt(1); // remove element at index 1

    cout << "After deletion: ";
    v.display();

    return 0;
}

