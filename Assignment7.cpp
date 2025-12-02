#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class sorter{
private:
	vector<T> data;

	void bubbleSort(bool ascending);
	void quickSort(int low, int high, bool ascending);

public:
	void addElement(const T& value){
		data.push_back(value);
	}

	void display() const {
		if(data.empty()){
			cout<<"No element to display";
			return;
		}
		for (const T& x : data) {
			cout << x << " ";
		}
		cout << endl;
	}

	void sort(bool ascending, int method){
		if(data.empty()){
			throw runtime_error("Cannot sort Empty List!");
		}
		if (method == 1) {
			bubbleSort(ascending);
		} 
		else if (method == 2) {
			quickSort(0, data.size() - 1, ascending);
		}
		else {
			throw invalid_argument("Invalid sorting method.");
		}
	}
};


template <typename T>
void sorter<T>::bubbleSort(bool ascending) {
	int n = data.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (ascending ? (data[j] > data[j + 1]) : (data[j] < data[j + 1])) {
				T temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

