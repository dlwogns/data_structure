#include <iostream>
using namespace std;

class Array {
private:
	int* arr;
	int arrSize;

public:
	Array(int sz) {
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < sz; i++) {
			arr[i] = 0;
		}
	}

	int at(int idx) {
		return arr[idx];
	}

	void add(int idx, int value) {//»ðÀÔ
		for (int i = arrSize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	void set(int idx, int value) { //ÇÒ´ç
		arr[idx] = value;
	}

	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void remove(int idx) {
		for (int i = idx + 1; i < arrSize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0;
	}
};