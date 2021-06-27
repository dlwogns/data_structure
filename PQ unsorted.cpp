#include <iostream>
#include <vector>
using namespace std;

class isLess { //비교자
public:
    bool operator()(const int a, int b)const {
        //int형 정수 a, b를 입력받아서
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

int PQ::min() { //가장 작은 원소 반환
    vector<int>::iterator p = v.begin(); //begin으로 반복자 p초기화
    isLess C; //비교자 선언
    int m_value = *v.begin(); //가장 작은 값을 저장할 변수 m_value를 반복자 p가 가리키는 값으로 초기화
    // 반복자 iter로 순차적으로 벡터의 원소에 접근
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