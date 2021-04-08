#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node* head;
    Node* tail;
    int list_size;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
        list_size = 0;
    }

    void Append(int data)
    {
        Node* newNode = new Node(data);

        if (head == NULL) // 기존에 노드가 아예 없을 때
        {
            head = newNode;
            tail = newNode;
            list_size++;
            Print();
        }

        else // 기존에 노드가 존재할 때
        {
            tail->next = newNode;
            tail = newNode;
            list_size++;
            Print();
        }
    }

    void Insert(int idx, int data)
    {
        Node* newNode = new Node(data);

        Node* pre_Node;
        Node* cur_Node;
        int cur_idx = 0;

        if (idx == 0)
        {
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
                list_size++;
                Print();
            }

            else
            {
                newNode->next = head;
                head = newNode;
                list_size++;
                Print();
            }
        }

        else if (idx < 0 || idx > list_size)
        {
            //cout << list_size << endl;
            cout << "Index Error" << endl;
        }

        else if (idx == list_size)
        {
            Append(data);
            Print();
        }

        else
        {
            pre_Node = cur_Node = head;

            while (cur_idx != idx)
            {
                pre_Node = cur_Node;
                cur_Node = cur_Node->next;
                cur_idx++;
            }

            pre_Node->next = newNode;
            newNode->next = cur_Node;
            list_size++;

            Print();
        }
    }

    void Delete(int idx)
    {
        int removeNum = 0;
        Node* cur_Node;
        Node* pre_Node;

        if (head == NULL || list_size <= idx)
        {
            cout << -1 << endl;
        }

        else if (idx == 0) // 맨 앞 데이터 삭제
        {
            if (list_size == 1) // 노드가 1개만 있을 때
            {
                Node* temp = head;
                removeNum = temp->data;

                head = NULL;
                tail = NULL;

                list_size--;

                delete temp;
            }

            else // 노드가 많을 때
            {
                cur_Node = head;
                removeNum = cur_Node->data;

                head = cur_Node->next;
                list_size--;

                delete cur_Node;
            }

            cout << removeNum << endl;
        }

        else // 노드 여러 개 중 중간 삭제
        {
            pre_Node = cur_Node = head;

            while (idx--)
            {
                pre_Node = cur_Node;
                cur_Node = cur_Node->next;
            }

            removeNum = cur_Node->data;

            if (cur_Node == tail)// 맨 뒤에 노드 삭제
            {
                tail = pre_Node;
                list_size--;
                tail->next = NULL;

                delete cur_Node;
            }

            else
            {
                Node* temp = cur_Node->next;
                pre_Node->next = temp;
                list_size--;

                delete cur_Node;
            }

            cout << removeNum << endl;
        }
    }

    void Print()
    {
        if (list_size == 0)
        {
            //cout << list_size << endl;
            cout << "empty" << endl;
        }

        else
        {
            Node* cur_Node = head;

            while (cur_Node->next != NULL)
            {
                cout << cur_Node->data << " ";
                cur_Node = cur_Node->next;
            }
            //cout << list_size << endl;
            cout << cur_Node->data << endl;
        }
    }

    void Min()
    {
        Node* cur_Node = head;

        if (list_size == 0)
        {
            //cout << list_size << endl;
            cout << "empty" << endl;
        }

        else
        {
            int min = cur_Node->data;
            cur_Node = cur_Node->next;
            list_size--;
            while (list_size--)
            {
                if (min > cur_Node->data)
                {
                    min = cur_Node->data;
                }
                cur_Node = cur_Node->next;
            }
            //cout << list_size << endl;
            cout << min << endl;
        }
    }
};

int main()
{
    int M;
    string command;
    int num1;
    int num2;
    int idx1;
    int idx2;

    cin >> M;

    LinkedList list;

    for (int i = 0; i < M; i++)
    {
        cin >> command;

        if (command == "Print")
        {
            list.Print();
        }

        else if (command == "Append")
        {
            cin >> num1;
            list.Append(num1);
        }

        else if (command == "Delete")
        {
            cin >> idx1;
            list.Delete(idx1);
        }

        else if (command == "Insert")
        {
            cin >> idx2 >> num2;
            list.Insert(idx2, num2);
        }

        else if (command == "Min")
        {
            list.Min();
        }
    }
}