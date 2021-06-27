#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};
class LinkedStack {
public:
	Node* head;
	Node* tail;
	int n;
	LinkedStack() {
		this->head = NULL;
		this->tail = NULL;
		this->n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		return n == 0;
	}
	int top() {
		if (empty()) return -1;
		else return head->data;
	}
	void push(int e) {
		Node* newNode = new Node(e);
		if (empty()) {
			head = tail = newNode;
			n++;
		}
		else {
			newNode->next = head;
			head = newNode;
			n++;
		}
	}
	int pop() {
		int ret;
		if (empty())return -1;
		else {
			Node* temp = head;
			head = head->next;
			ret = temp->data;
			delete temp;
			n--;
			return ret;

			/*Node* temp = head;
			head = head->next;
			n--;
			return temp->data;*/ /*이게 원래 코드*/
		}
	}
};

int main() {
	int N;
	string s;
	LinkedStack st;
	cin >> N;
	while (N--)
	{
		cin >> s;
		for (auto e : s) {
			if (e > '0' && e <= '9') {
				st.push(e);
			}
			else if (e == '*') {

			}
			else if (e == '+') {

			}
			else if (e == '-') {

			}
		}
	}
}