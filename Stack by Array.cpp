#include <iostream>
#include <string>
using namespace std;

class arrStack {
public:
    int* arr;
    int capacity;
    int t;

    arrStack(int capacity) {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->t = -1;
    }

    int size() {
        return t + 1;
    }
    bool empty() {
        return t == -1;
    }
    int top() {
        if (empty()) return -1;
        else return arr[t];
    }
    void push(int e) {
        if (size() == capacity) cout << "FULL" << endl;
        else arr[++t] = e;
    }
    int pop() {
        if (empty()) return -1;
        return arr[t--];
    }
};