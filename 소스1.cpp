#include<iostream>
using namespace std;

class SequenceList
{
private:
    struct Node
    {
        int e;                              //원소를 저장할 변수
        Node* prev;                           //이전 노드를 가리키는 포인터
        Node* next;                           //다음 노드를 가리키는 포인터
    };

public:
    class Iterator                           //반복자 클래스
    {
    public:
        Node* v;                           //반복자가 가리키는 노드를 저장하기 위한 포인터 변수
        Iterator(Node* u)                     //반복자 생성
        {
            v = u;
        }
        int& operator*()                     //반복자가 가리키고 있는 노드가 가지고 있는 
        {
            return v->e;
        }
        bool operator==(const Iterator& p) const
        {
            return v == p.v;
        }
        bool operator!=(const Iterator& p) const
        {
            return v != p.v;
        }
        Iterator& operator++()
        {
            v = v->next;
            return *this;
        }
        Iterator& operator--()
        {
            v = v->prev;
            return *this;
        }

        friend class SequenceList;
    };

private:
    int n;
    Node* header;
    Node* trailer;

public:
    SequenceList()
    {
        n = 0;
        header = new Node;
        trailer = new Node;
        header->next = trailer;
        trailer->prev = header;
    }

    int size() const
    {
        return n;
    }

    bool empty() const
    {
        return n == 0;
    }

    Iterator begin() const
    {
        return Iterator(header->next);
    }

    Iterator end() const
    {
        return Iterator(trailer);
    }

    void InsertFront(const int& e)
    {
        insert(begin(), e);
    }

    void InsertBack(const int& e)
    {
        insert(end(), e);
    }

    void insert(const Iterator& p, const int& e)
    {
        //원래 순서 : u - w
        //insert이 후 순서 : u - v - w
        Node* w = p.v;
        Node* u = w->prev;
        Node* v = new Node; //새로 삽입되는 노드

        v->e = e;
        v->next = w;
        w->prev = v;
        v->prev = u;
        u->next = v;

        this->n++;
    }

    void eraseFront()
    {
        erase(begin());
    }

    void eraseBack()
    {
        erase(--end());
    }

    void erase(const Iterator& p)
    {
        if (n == 0)
        {
            cout << "Empty" << endl;
        }

        else
        {
            //원래 순서 : u - v - w
            //erase 이후 순서 : u - w
            Node* v = p.v;
            Node* w = v->next;
            Node* u = v->prev;

            u->next = w;
            w->prev = u;
            delete v;

            this->n--;
        }
    }

    Iterator atIndex(int i) const
    {
        Iterator p = begin();
        for (int j = 0; j < i; j++)
        {
            ++p;
        }
        return p;
    }
    int indexOf(const Iterator& p) const
    {
        Iterator q = begin();
        int j = 0;

        while (q != p)
        {
            ++q;
            ++j;
        }
        return j;
    }

    void print()
    {
        if (!this->empty()) {
            Iterator p = this->begin();

            while (p != this->end())
            {
                cout << *p << " ";
                ++p;
            }

            cout << endl;
        }
        else
            cout << "Empty" << endl;
    }

    void find(const int& value)
    {
        if (this->empty())
        {
            cout << "Empty" << endl;
        }

        else
        {
            Iterator p = this->begin();
            int index = 0;

            while (p != this->end())
            {
                if (*p == value)
                {
                    cout << index << endl;
                    break;
                }
                ++p;
                index++;
            }

            if (n == index)
            {
                cout << "-1" << endl;
            }
        }
    }

};

int main()
{
    int M; //명령어의 수
    cin >> M;
    string command;
    int value1;
    int value2;
    SequenceList dl;
    SequenceList::Iterator iter = dl.begin();

    for (int i = 0; i < M; i++)
    {
        cin >> command;

        if (command == "begin")
        {
            dl.begin();
        }

        else if (command == "end")
        {
            dl.end();
        }

        else if (command == "insert")
        {
            cin >> value1;
            dl.insert(iter, value1);
        }

        else if (command == "erase")
        {
            dl.erase(iter);
        }

        else if (command == "++")
        {
            ++iter;
        }

        else if (command == "--")
        {
            --iter;
        }

        else if (command == "print")
        {
            dl.print();
        }

        else if (command == "find")
        {
            cin >> value2;
            dl.find(value2);
        }
    }

    return 0;
}