#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
	vector<int>v;
public:
	Heap() {
		v.push_back(0);
	}
	void insert(int a) {
		if (v.size()==1) {
			v.push_back(a);
			return;
		}
		//upheap

		v.push_back(a);
		int size = v.size()-1;
		while (1) {
			
			if (size == 1) {
				break;
			}else if (v[size/2] < a) {
				int tmp = v[size / 2];
				v[size / 2] = v[size];
				v[size ] = tmp;
				size = size / 2;
			}
			else {
				break;
			}
		}


	}
	int size() {
		return v.size()-1;

	}
	int isEmpty() {
		if (v.size()==1)
			return 1;
		else
			return 0;

	}
	int pop() {
		//popMax
		if (isEmpty())
			return -1;

		int max = v[1];
		v[1] = v.back();
		v.pop_back();
		//downheap
		int idx = 1;
		
		while (1) {
			int left = idx * 2;
			int right = idx * 2 + 1;
			
			if (right <= v.size() - 1) {
				if (v[left] > v[idx] && v[left] > v[right]) {
					int tmp = v[left];
					v[left] = v[idx];
					v[idx] = tmp;
					idx = left;
				}
				else if (v[right] > v[idx]) {
					int tmp = v[right];
					v[right] = v[idx];
					v[idx] = tmp;
					idx = right;
				}
				else {
					break;	
				}
			}
			else if (left <= v.size() - 1) {
				if (v[left] > v[idx]) {
					int tmp = v[left];
					v[left] = v[idx];
					v[idx] = tmp;
					idx = left;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}

		return max;



	}
	int top() {
		//max
		if (v.size()==1)
			return -1;
		else {
			return v[1];
		}
	}
	void print() {
		if (v.size()==1){
			cout << -1;
			return;
	}
		for (size_t i = 1; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		
	}
};

int main() {

	int T;
	string s;
	cin >> T;
	Heap h;
	while (T--) {
		cin >> s;
		if (s == "insert") {
			int a;
			cin >> a;
			h.insert(a);
		}
		else if (s == "size") {
			cout << h.size() << endl;
		}
		else if (s == "isEmpty") {
			cout << h.isEmpty() << endl;

		}
		else if (s == "pop") {
			cout << h.pop() << endl;
		}
		else if (s == "top") {
			cout << h.top() << endl;
		}
		else if (s == "print") {
			h.print();
			cout << "\n";
		}


	}

}