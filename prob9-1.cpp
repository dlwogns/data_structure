#include <iostream>
#include <vector>
using namespace std;
// �Է��� ������ ���ĵ��� ���� �Է°����� �����ϰ�, ���ö����� PQ�� �̿��Ѵٴ� �������� ǰ.
class PQ {
private:
	vector<int>v;

public:
	void insert(int a) {
		if (v.empty())
			v.push_back(a);
		else {
			vector<int>::iterator i = v.begin();
			while ( i != v.end() && *i < a) { //*i>a�� �ٲ��ָ� 2������
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