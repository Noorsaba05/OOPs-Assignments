#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class SimpleSorter {
private:
    T arr[20];
    int size;

public:
    SimpleSorter() {
        size = 0;
    }

    void addElement(T value) {
        if (size >= 20) {
            throw runtime_error("Array is full");
        }
        arr[size] = value;
        size++;
    }

    void bubbleSort(bool ascending = true) {
        if (size == 0) {
            throw runtime_error("No elements to sort");
        }

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                bool condition = ascending ?
                                 (arr[j] > arr[j + 1]) :
                                 (arr[j] < arr[j + 1]);

                if (condition) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void display() {
        if (size == 0) {
            throw runtime_error("No elements to display");
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        SimpleSorter<string> s;

        s.addElement("a");
        s.addElement("bt");
        s.addElement("c");

        s.bubbleSort(false);  
        s.display();
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
