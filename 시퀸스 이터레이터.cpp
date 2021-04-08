#include <iostream>
using namespace std;

class SequenceList {
private:
    struct Node {
        int e;
        Node* prev;
        Node* next;
    };
public:
    class iterator {
    private:
        Node* v;
        iterator(Node* u);
    public:
        int& operator*();
        bool operator==(const iterator& p) const;
        bool operator!=(const iterator& p) const;
        iterator& operator++();
        iterator& operator--();

        friend class SequenceList;
    };

private:
    int n;
    Node* header;
    Node* trailer;
public:
    SequenceList();
    int size() const;
    bool empty() const;
    iterator begin()const;
    iterator end() const;
    void insertFront(const int& e);
    void insertBack(const int& e);
    void erase(const iterator& p);
    void insert(const iterator& p, const int& e);
    void eraseFront();
    void eraseBack();
    void print();
    void find(int a);


    SequenceList::iterator atindex(int i) const;
    int indexOf(const iterator& p);
};



SequenceList::SequenceList() {
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;

}

void SequenceList::print() {
    if (this->empty()) {
        SequenceList::iterator i = this->begin();
        while (i != this->end())
            cout << *i << " ";
        cout << "\n";
    }
    else
        cout << "Empty" << endl;
}
void SequenceList::find(int a)
{
    SequenceList::iterator i = this->begin();
    while (i != this->end()) {
        if (a == *i)
            cout << *i << endl;
        else
            cout << "Empty" << endl;
    }
}
int SequenceList::size() const
{
    return n;
}
bool SequenceList::empty() const
{
    return (n == 0);
}
SequenceList::iterator SequenceList::begin() const
{
    return iterator(header->next);
}
SequenceList::iterator SequenceList::end() const
{
    return iterator(trailer);
}
void SequenceList::insert(const SequenceList::iterator& p, const int& e) {
    Node* w = p.v; //iterator가 가리키는 node -> w
    Node* u = w->prev; // w.prev
    Node* v = new Node; // insert를 위한 새로운 노드
    v->e = e;
    v->next = w;
    w->prev = v;
    v->prev = u;
    u->next = v;
    this->n++;
}
void SequenceList::eraseFront()
{
    erase(begin());
}
void SequenceList::eraseBack()
{
    erase(--end());
}
SequenceList::iterator SequenceList::atindex(int i) const
{
    iterator p = begin();
    for (int j = 0; j < i; j++) {
        ++p;
    }
    return p;
}
int SequenceList::indexOf(const iterator& p)
{
    iterator q = begin();
    int j = 0;
    while (q != p) {
        ++q;
        ++j;
    }
    return j;
}
void SequenceList::insertFront(const int& e) {
    insert(begin(), e);
}
void SequenceList::insertBack(const int& e) {
    insert(end(), e);
}
void SequenceList::erase(const iterator& p) {
    if (this->empty())
        cout << "Empty" << endl;
    else {

        Node* v = p.v;
        Node* w = v->next;
        Node* u = v->prev;
        u->next = w; w->prev = u;
        delete v;
        this->n--;
    }

}

SequenceList::iterator::iterator(Node* u)
{
    v = u;
}

int& SequenceList::iterator::operator*() {
    return v->e;
}

bool SequenceList::iterator::operator==(const iterator& p) const
{
    return v == p.v;
}

bool SequenceList::iterator::operator!=(const iterator& p) const
{
    return v != p.v;
}

SequenceList::iterator& SequenceList::iterator::operator++()
{
    v = v->next;
    return *this;
}

SequenceList::iterator& SequenceList::iterator::operator--()
{
    v = v->prev;
    return *this;
}

int main() {
    int T;
    cin >> T;
    SequenceList dl;
    SequenceList::iterator iter = dl.begin();
    for (size_t i = 0; i < T; i++)
    {
        string oper;
        cin >> oper;
        if (oper == "begin") {
            iter = dl.begin();
        }
        else if (oper == "end") {
            iter = dl.end();
        }
        else if (oper == "insert") {
            int a;
            cin >> a;
            dl.insert(iter, a);
        }
        else if (oper == "erase") {
            dl.erase(iter);
        }
        else if (oper == "++") {
            ++iter;
        }
        else if (oper == "--") {
            --iter;
        }
        else if (oper == "print") {
            dl.print();
        }
        else if (oper == "find") {

        }
    }
}