#include <iostream>
#include <string>
using namespace std;

class Histogram {
private:
	int arr[26] = { 0 };
public:
	Histogram(string s) {
		//��Ʈ�� �޾Ƽ� arr�� a���� z���� �ִ� �˰���
	}
	int stsize(string s) {
		return s.size();
	}
	void printhisto() {
		for (int i = 0; i < 27; i++) {
			// ����Ʈ
		}
	}
};
int main() {
	string s;
	cin >> s;
	Histogram his(s);
	his.printhisto();
}