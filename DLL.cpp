#include <iostream>
#include <string>
using namespace std;

class Node {
    int elem;
    Node* next;

    friend class S_LinkedList;
};

class S_LinkedList {
public:
    S_LinkedList()
    {
        head = new Node;
        tail = new Node;
        head = NULL;
        tail = NULL;
    }
    void Print()
    {
        if (head == NULL && tail == NULL)
            cout << "empty" << endl;
        else
        {
            Node* cur_node = head;
            if (cur_node->next == NULL)
            {
                cout << cur_node->elem << " ";
            }
            else
            {
                while (cur_node != NULL)
                {
                    cout << cur_node->elem << " ";
                    cur_node = cur_node->next;
                }
            }
            cout << endl;
        }
    }
    void Append(int x)
    {
        Node* new_node = new Node;
        new_node->elem = x;
        new_node->next = NULL;
        if (head == NULL && tail == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;
        }
    }
    void Delete(int i)
    {
        Node* cur_node = head;
        Node* pre_node = NULL;
        int index{ 0 };
        if (i <= size || (head == NULL && tail == NULL))
        {
            cout << "-1" << endl;
        }
        else if (index == i)
        {
            cout << cur_node->elem << endl;
            tail = NULL;
            head = NULL;
        }
        else
        {
            while (index != i && cur_node->next != NULL)
            {
                pre_node = cur_node;
                cur_node = cur_node->next;
                index += 1;
            }
            cout << cur_node->elem << endl;
            if (cur_node == tail)
            {
                pre_node = tail;
                pre_node->next = NULL;
            }
            else if (cur_node == head)
            {
                cur_node->next = head;
            }
            else
            {
                pre_node->next = cur_node->next;
            }
        }
    }
    void Insert(int i, int x)
    {
        Node* cur_node = head;
        Node* pre_node = NULL;
        int index{ 0 };
        if (i > size)
        {
            cout << "index Error" << endl;
        }
        else
        {
            while (index != i)
            {
                pre_node = cur_node;
                cur_node = cur_node->next;
                index += 1;
            }
            Node* new_node = new Node;
            new_node->elem = x;
            pre_node->next = new_node;
            new_node->next = cur_node;
            this->Print();
        }
    }
    void Sum()
    {
        int sum{ 0 };
        if (head == NULL && tail == NULL)
            cout << sum << endl;
        else
        {
            Node* cur_node = head;
            while (cur_node != NULL)
            {
                sum += cur_node->elem;
                cur_node = cur_node->next;
            }
            cout << sum << endl;
        }
    }
private:
    Node* head;
    Node* tail;
    int size{ 0 };
};

int main()
{
    int cnt;
    cin >> cnt;
    int  b, c;
    S_LinkedList s;

    for (int i{ 0 }; i < cnt; i++)
    {
        string s1;
        cin >> s1;
        if (s1 == "Print")
        {
            s.Print();
        }
        if (s1 == "Append")
        {
            cin >> b;
            s.Append(b);
            s.Print();
        }
        if (s1 == "Delete")
        {
            cin >> b;
            s.Delete(b);
        }
        if (s1 == "Insert")
        {
            cin >> b >> c;
            s.Insert(b, c);
        }
        if (s1 == "Sum")
        {
            s.Sum();
        }
    }
}