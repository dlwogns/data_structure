#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}

};
class LinkedList {
public:
	Node* front;
	Node* rear;

	LinkedList() {
		this->front = NULL;
		this->rear = NULL;
	}
	void addEnd(int data) {
		Node* newNode = new Node(data);
		if (front == NULL) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}
	void removeFront() {
		if (front != NULL) {
			Node* tmp = front;
			front = front->next;
			delete tmp;
		}
	}

};

class LinkedQueue {
public:
	LinkedList* Q;
	int n;

	LinkedQueue() {
		this->Q = new LinkedList();
		this->n = 0; //큐 안에 삽입된 원소의 개수
	}
	int size() {
		return n;
	}
	bool isEmpty() {
		return n == 0;
	}
	int front() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return Q->front->data;
		}
	}
	void enqueue(int e) {
		Q->addEnd(e);
		n++;
	}
	void dequeue() {
		if (isEmpty()) cout << "Empty" << endl;
		else {
			Q->removeFront();
			n--;
		}
	}
};

int main() {
	int T;
	cin >> T;
	LinkedQueue q1;
	LinkedQueue q2;
	while (T--) {
		int a;
		int p1 = 0, p2 = 0;
		int c1 = 0, c2 = 0;
		cin >> a;
		for (size_t i = 0; i < a; i++)
		{
			int a1;
			cin >> a1;
			q1.enqueue(a1);
		}
		for (size_t i = 0; i < a; i++)
		{
			int a1;
			cin >> a1;
			q2.enqueue(a1);
		}
		for (size_t i = 0; i < a; i++)
		{
			int w1 = c1 + q1.front();
			int w2 = c2 + q2.front();
			if (w1 > w2)
			{
				c1 = w1 - w2;
				q1.dequeue();
				q2.dequeue();
				c2 = 0;
				p1++;
			}
			else if (w1 < w2) {
				c2 = w2 - w1;
				q1.dequeue();
				q2.dequeue();
				c1 = 0;
				p2++;
			}
			else {
				q1.dequeue();
				q2.dequeue();
				c1 = 0; c2 = 0;
			}

		}
		if (p1 > p2)
			cout << 1 << endl;
		else if (p2 > p1)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}

}