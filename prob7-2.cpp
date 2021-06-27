#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<math.h>

using namespace std;

class Node {
public:
    vector <Node*> child;
    int data;
    Node* par_node;

};

class tree {
public:
    Node* root;
    vector <Node*> v_node;
    tree() {
        Node* newNode = new Node();
        newNode->data = 1;
        root = newNode;
        v_node.push_back(root);
    }
    void insertXY(int parent, int data);
    void postOrder(Node* v);
};

void tree::insertXY(int parent, int data) {
    Node* newnode = new Node();
    newnode->data = data;
    for (int i = 0; i < v_node.size(); i++) {
        if (v_node[i]->data == parent) {
            newnode->par_node = v_node[i];
            v_node[i]->child.push_back(newnode);
            v_node.push_back(newnode);
        }
    }
}

void tree::postOrder(Node* v) {

    for (int i = 0; i < v->child.size(); i++) {
        postOrder(v->child[i]);
    }
    cout << v->data << " ";
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int testCase;
    cin >> testCase;
    int treeNum = 0;
    while (testCase--) {
        vector <int> data_v;
        vector <int> depth_v;
        tree t;
        int number;
        cin >> number;
        int num = number;
        while (num--) {
            int data;
            cin >> data;
            data_v.push_back(data);
        }
        num = number;
        while (num--) {
            int depth;
            cin >> depth;
            depth_v.push_back(depth);
        }
        for (int i = 0; i < depth_v.size(); i++) {
            for (int k = i + 1; k < depth_v.size(); k++) {
                if (depth_v[i] == depth_v[k] - 1) {
                    t.insertXY(data_v[i], data_v[k]);
                }
                else if (depth_v[i] == depth_v[k]) {
                    break;
                }
            }
        }
        t.postOrder(t.root);
        treeNum++;
    }
}