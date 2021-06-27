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
    v.push_back(e);
}

int PQ::min() { //���� ���� ���� ��ȯ
    vector<int>::iterator p = v.begin(); //begin���� �ݺ��� p�ʱ�ȭ
    isLess C; //���� ����
    int m_value = *v.begin(); //���� ���� ���� ������ ���� m_value�� �ݺ��� p�� ����Ű�� ������ �ʱ�ȭ
    // �ݺ��� iter�� ���������� ������ ���ҿ� ����
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        if (!C(m_value, *iter)) {
            m_value = *iter;
            p = iter;
        }
    }
    return *p;
}

void PQ::removeMin() {
    vector<int>::iterator p = v.begin();
    isLess C;
    int m_value = *v.begin();

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        if (!C(m_value, *iter)) {
            m_value = *iter;
            p = iter;
        }
    }

    v.erase(p);
}