#include <iostream>
using namespace std;

class arrQ {
private:
	int* Q;
	int rear;
	int front;
	int capacity;

public:
	arrQ(int capacity) {
		this->capacity = capacity + 1; //���� ť �̹Ƿ�, ���� �ϳ� �� �ʿ��ϴ�.
		Q = new int[this->capacity];
		front = rear = 0;

		for (int i = 0; i < capacity; i++) {
			Q[i] = 0;
		}
	}

	void enqueue(int value) {
		if (isFull()) { cout << "Full" << endl; }
		else {
			rear = (rear + 1) % capacity;
			Q[rear] = value;
		}

	}
	void dequeue() {
		if (isEmpty()) { cout << "Empty" << endl; }
		else {
			front = (front + 1) % capacity;
			Q[front] = 0; //front�� ������ ����־�� ������ ����.
		}
	}
	void _front() {
		if (isEmpty()) cout << "Empty" << endl;
		else cout << Q[(front + 1) % capacity] << endl;
	}
	void _rear() {
		if (isEmpty()) cout << "Empty" << endl;
		else cout << Q[rear] << endl;
	}
	int size() {
		return (rear - front + capacity) % capacity;
	}
	bool isFull() {
		return front == (rear + 1) % capacity; //rear�� front �ٷ� �տ� �ִ� ���
	}
	bool isEmpty() {
		return front == rear;
	}
};