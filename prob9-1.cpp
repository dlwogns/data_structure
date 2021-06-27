#include <iostream>
#include <vector>
using namespace std;
// 입력할 수들을 정렬되지 않은 입력값으로 간주하고, 들어올때마다 PQ를 이용한다는 방향으로 품.
class PQ {
private:
	vector<int>v;

public:
	void insert(int a) {
		if (v.empty())
			v.push_back(a);
		else {
			vector<int>::iterator i = v.begin();
			while ( i != v.end() && *i < a) { //*i>a로 바꿔주면 2번문제
				i++;
			}
			v.insert(i, a);
			
		}
	}
	void print() {
		for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
			cout << *i << ' ';
		}
		cout << "\n";
	}
};

int main() {

	int T;
	cin >> T;


	while (T--) {
		PQ pq;
		int N;
		cin >> N;
		while (N--) {
			int a;
			cin >> a;
			pq.insert(a);

		}
		pq.print();
	}
}