#include <iostream>
#include <string>
using namespace std;

class Histogram {
private:
	int arr[26] = { 0 };
public:
	Histogram(string s) {
		//스트링 받아서 arr에 a부터 z까지 넣는 알고리즘
	}
	int stsize(string s) {
		return s.size();
	}
	void printhisto() {
		for (int i = 0; i < 27; i++) {
			// 프린트
		}
	}
};
int main() {
	string s;
	cin >> s;
	Histogram his(s);
	his.printhisto();
}