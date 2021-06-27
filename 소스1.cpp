#include<iostream>
using namespace std;

class SequenceList
{
private:
    struct Node
    {
        int e;                              //���Ҹ� ������ ����
        Node* prev;                           //���� ��带 ����Ű�� ������
        Node* next;                           //���� ��带 ����Ű�� ������
    };

public:
    class Iterator                           //�ݺ��� Ŭ����
    {
    public:
        Node* v;                           //�ݺ��ڰ� ����Ű�� ��带 �����ϱ� ���� ������ ����
        Iterator(Node* u)                     //�ݺ��� ����
        {
            v = u;
        }
        int& operator*()                     //�ݺ��ڰ� ����Ű�� �ִ� ��尡 ������ �ִ� 
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
        //���� ���� : u - w
        //insert�� �� ���� : u - v - w
        Node* w = p.v;
        Node* u = w->prev;
        Node* v = new Node; //���� ���ԵǴ� ���

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
            //���� ���� : u - v - w
            //erase ���� ���� : u - w
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
    int M; //��ɾ��� ��
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