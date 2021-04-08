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
class linkedStack {
public:
    Node* head;
    Node* tail;
    int n;

    linkedStack() {
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
        else
        {
            newNode->next = head;
            head = newNode;
            n++;
        }
    }
    int pop() {
        if (empty()) return -1;
        else {
            Node* temp = head;
            head = head->next;
            n--;
            return temp->data;
        }
    }
};

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        linkedStack var;

        for (auto e : s) {
            if (e >= '1' && e <= '9') {
                var.push(int(e - '0'));
            }
            else {
                if (e == '+') {
                    int x = var.pop();
                    int y = var.pop();
                    var.push(x + y);
                }
                else if (e == '-') {
                    int y = var.pop();
                    int x = var.pop();
                    var.push(x - y);
                }
                else {
                    int x = var.pop();
                    int y = var.pop();
                    var.push(x * y);
                }
            }
        }
        cout << var.pop() << endl;
    }

}
