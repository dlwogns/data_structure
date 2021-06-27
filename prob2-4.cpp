#include <iostream>
using namespace std;

class Node {
	int elem;
	Node* next;
	Node* prev;
	Node() {
		next = NULL;
		prev = NULL;
	}
	friend class DLL;
};

class DLL {
private:
	Node* head;
	Node* tail;
	int size;
public:
	DLL() {
		head = new Node;
		tail = new Node;
		size = 0;
		head = NULL;
		tail = NULL;
	}
	bool Empty() {
		return head == NULL;

	}
	void Print() {
		if (Empty()) {
			cout << "empty" << endl;
		}
		else {
			Node* cur_node = head;
			while (cur_node->next != NULL) {
				cout << cur_node->elem << ' ';
				cur_node = cur_node->next;
			}
			cout << cur_node->elem << endl;
		}
	}
	void Append(int data) {
		Node* new_node = new Node;
		new_node->elem = data;
		new_node->next = NULL;
		new_node->prev = NULL;
		if (Empty()) {
			head = new_node;
			tail = new_node;
			size++;
		}
		else {
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
			size++;
		}
	}
	int Delete(int idx) {
		int ret = 0;
		Node* cur_node = head;

		if (Empty() || size <= idx)
			return -1;
		else {
			while (idx--) {
				cur_node = cur_node->next;
			}
			if (cur_node == head) {
				ret = cur_node->elem;
				cur_node->next->prev = NULL;
				head = cur_node->next;
			}
			else if (cur_node == tail) {
				ret = cur_node->elem;
				cur_node->prev->next = NULL;
				tail = cur_node->prev;
			}
			else {
				ret = cur_node->elem;
				cur_node->prev->next = cur_node->next;
				cur_node->next->prev = cur_node->prev;
			}
			size--;
			Node* tmp = cur_node;
			delete cur_node;
			return ret;

		}

	}
	void Print_reverse() {
		if (Empty())
			cout << "empty" << endl;
		else {
			Node* cur_node = tail;
			while (cur_node->prev != NULL) {
				cout << cur_node->elem << " ";
				cur_node = cur_node->prev;
			}
			cout << cur_node->elem << endl;
		}
	}
	void Max() {
		if (Empty())
			cout << "empty" << endl;
		else {
			Node* cur_node = head;
			int max = 0;
			while (cur_node != NULL) {
				if (max < cur_node->elem)
					max = cur_node->elem;
				cur_node = cur_node->next; //시험전에 다시보기. while문에 cur_node->next = NULL이라고 안써도 된다.
			}
			cout << max << endl;
		}
	}
	void Sum() {
		if (Empty())
			cout << 0 << endl;
		else {
			Node* cur_node = head;
			int sum = 0;
			while (cur_node != NULL) {
				sum += cur_node->elem;
				cur_node = cur_node->next;
			}
			cout << sum << endl;
		}
	}
};
int main() {
	int N;
	cin >> N;
	DLL sll;
	while (N--) {
		string s;
		cin >> s;
		if (s == "Print")
			sll.Print();
		else if (s == "Append") {
			int a;
			cin >> a;
			sll.Append(a);
			sll.Print();
		}
		else if (s == "Delete") {
			int a;
			cin >> a;
			cout << sll.Delete(a) << endl;

		}
		else if (s == "Print_reverse") {
			sll.Print_reverse();
		}
		else if (s == "Max") {
			sll.Max();
		}
		else if (s == "Sum") {
			sll.Sum();
		}
	}

}