#include <iostream>
#include <stack>
using namespace std;
string s;
stack<char>oper;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string ans;
	cin >> s;

	for (auto e : s) {
		if (e >= 'A' && e <= 'Z') {
			ans.push_back(e);
		}
		else if (e == '(') {
			oper.push(e);
		}
		else if (e == ')') {
			while (!oper.empty() && !(oper.top() == '(')) {
				ans.push_back(oper.top());
				oper.pop();
			}
			oper.pop();
		}
		else if (e == '*' || e == '/') {
			if (!oper.empty() && (oper.top() == '*' || oper.top() == '/')) {
				ans.push_back(oper.top());
				oper.pop();

			}
			oper.push(e);
		}
		else if (e == '+' || e == '-') {
			while (!oper.empty() && oper.top() != '(') {
				ans.push_back(oper.top());
				oper.pop();
			}
			oper.push(e);
		}
	}
	if (!oper.empty()) {
		while (!oper.empty())
		{
			ans.push_back(oper.top());
			oper.pop();
		}
	}
	cout << ans;
}