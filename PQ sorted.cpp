#include <iostream>
#include <vector>
using namespace std;

class isLess { //����
public:
    bool operator()(const int a, int b)const {
        //int�� ���� a, b�� �Է¹޾Ƽ�
        if (a < b) {
            return true;

        }
        else {
            return false;
        }

    }
};

class PQ {
private:
    vector<int>v;
public:
    int size();
    bool empty();
    void insert(int e);
    int min();
    void removeMin();
    void print();
};

int PQ::size() {
    return v.size();
}
bool PQ::empty() {
    return v.size() == 0;
}
void PQ::print() {
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;
}
void PQ::insert(int e) {
    vector<int>::iterator p = v.begin();
    isLess C;
    if (v.empty()) {
        v.insert(p, e);
    }
    else {
        while (p != v.end() && C(e, *p)) {
            ++p;
        }
        v.insert(p, e);
    }
}
int PQ::min() {
    return v.back();
}
void PQ::removeMin() {
    v.pop_back();
}