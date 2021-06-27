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

	void at(int idx) {
		cout << arr[idx] << endl;
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
	}

	void find_max() {
		int max = 0;
		for (size_t i = 0; i < arrSize; i++)
		{
			if (arr[i] > max)
				max = arr[i];
		}
		cout << max << endl;

	}
};

int main() {
	int N, T;
	cin >> N >> T;
	Array arr(N);
	while (T--)
	{
		string s;
		cin >> s;
		if (s == "at") {
			int a;
			cin >> a;
			arr.at(a);
		}
		else if (s == "add") {
			int a, b;
			cin >> a >> b;
			arr.add(a, b);
		}
		else if (s == "remove") {
			int a;
			cin >> a;
			arr.remove(a);
		}
		else if (s == "set") {
			int a, b;
			cin >> a >> b;
			arr.set(a, b);
			cout << b << endl;;
		}
		else if (s == "print") {
			arr.print();

		}
		else if (s == "find_max") {
			arr.find_max();
		}
	}

}