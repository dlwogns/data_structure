#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* par;
	vector<Node*> chi_v;

	Node(int data) {
		this->data = data;
		this->par = NULL;
	}
};

class Tree {
public:
	Node* root; //��Ʈ
	vector<Node*> node_v; //��� ��带 ������ ����

	Tree(int);
	void insertNode(int, int);
	void delNode(int);
	void printChi(int);
	void printPar(int);
	void printDepth(int);
	void printLevel(int);
	void preorder(Node*);
	void postorder(Node*);
};

Tree::Tree(int data) {
	Node* node = new Node(data);
	this->root = node;
	this->node_v.push_back(node);
}

void Tree::insertNode(int par_data, int data) { //�ش� �θ��忡 ���ο� ��带 ����
	Node* node = new Node(data);
	for (int i = 0; i < node_v.size(); i++) { // ��� ��带 ������ ���͸� ������ ���鼭 Ȯ��
		if (node_v[i]->data == par_data) {
			node_v[i]->chi_v.push_back(node); //�ش� �θ��忡 ���ο� ��� ����
			node_v.push_back(node); //��� ��带 ������ ���Ϳ� ����
			node->par = node_v[i]; //�θ� ����� �ڽ� ��� ���Ϳ� ����
			return;
		}
	}
	cout << -1 << endl;
}

void Tree::delNode(int data) {
	Node* curNode;
	Node* parNode;
	for (int i = 0; i < node_v.size(); i++) {
		if (node_v[i]->data == data) {

			if (node_v[i] == root) {
				cout << -1 << endl;
				return;
			}

			//�ڽ� ������ �θ� ����� chi_v�� �ֱ�
			curNode = node_v[i];
			parNode = curNode->par;
			for (Node* child : curNode->chi_v) {
				parNode->chi_v.push_back(child);
				child->par = parNode;
			}

			//���� ��忡�� ������ ��� ����
			for (int j = 0; j < parNode->chi_v.size(); j++) {
				if (parNode->chi_v[j]->data == data) {
					parNode->chi_v.erase(parNode->chi_v.begin() + j);
				}
			}

			//node_v���� ����
			node_v.erase(node_v.begin() + i);
			delete curNode;
			return;
		}
	}

	cout << -1 << endl;
}


void Tree::preorder(Node* node) {
	if (!node) return;

	cout << node->data << " "; //visit �κ� -> ����� ������ ���
	for (int i = 0; i < node->chi_v.size(); i++) {
		preorder(node->chi_v[i]);
	}
}

void Tree::postorder(Node* node) {
	if (!node) return;


	for (int i = 0; i < node->chi_v.size(); i++) {
		postorder(node->chi_v[i]);

		cout << node->data << " ";
	}
}

void Tree::printChi(int data) {
	for (size_t i = 0; i < node_v.size(); i++)
	{
		if (node_v[i]->data == data) {
			if (node_v[i]->chi_v.empty()) {
				cout << -1 << endl;
				return;
			}
			for (Node* child : node_v[i]->chi_v) {
				cout << child->data << " ";
			}
			cout << endl;
			return;
		}
	}
	cout << -1 << endl;
}

void Tree::printPar(int data) {
	for (size_t i = 0; i < node_v.size(); i++)
	{
		if (node_v[i]->chi_v.empty()) {
			if (node_v[i] == root) {
				cout << -1 << endl;
				return;
			}
			cout << node_v[i]->par->data << endl;
			return;
		}
	}
	cout << -1 << endl;;
}

int main() {

	int T;
	string s;
	cin >> T;
	Tree t(1);
	for (size_t i = 0; i < T; i++)
	{
		cin >> s;
		if (s == "insert") {
			int a, b;
			cin >> a >> b;
			t.insertNode(a, b);
		}
		else if (s == "delete") {
			int a;
			cin >> a;
			t.delNode(a);
		}
		else if (s == "print") {
			int a;
			cin >> a;
			t.printChi(a);
		}

	}
}