#include <iostream>
#include <vector>
using namespace std;
class Node {
private:
	int data;
	int checked = 0;
	Node* par;
	Node* left;
	Node* right;

public:
	Node(int);
	void setLeft(Node*);
	void setRight(Node*);

	friend class BST;
};

Node::Node(int data) {
	this->data = data;
	this->par = NULL;
	this->left = NULL;
	this->right = NULL;
}

void Node::setLeft(Node* node) {
	if (node == NULL) {
		this->left->par = NULL;
		this->left = NULL;
	}
	else {
		this->left = node;
		node->par = this;
	}
}
void Node::setRight(Node* node) {
	if (node == NULL) {
		this->right->par = NULL;
		this->right = NULL;
	}
	else
	{
		this->left = node;
		node->par = this;
	}
}

class BST {


public:
	vector<int>v;
	int idx = 0;
	Node* root;
	BST() {
		this->root = NULL;
	}
	void Delete(int k) {
		Node* node = search(k);
		if (node->left == NULL && node->right == NULL) {

		}
		else if () {

		}
		else {

		}
	}

	int sub(int x) {
		Node* n = search(x);
		if (n == NULL)
			return 0;
		inorder(n);
		int size = v.size();
		v.clear();
		return size;
		
		
		
		/*if (n == NULL)
			return 0;
		if (n->left == NULL && n->right == NULL) {
			
			return 1;
		}
		else if (n->left == NULL) {
			return 1+sub(n->right->data);
		}
		else if (n->right == NULL) {
			return 1+sub(n->left->data);
		}
		else {
			return 1+sub(n->right->data) + sub(n->left->data);
		}*/
		

		

	}
	Node* inorder(Node* a) {
		/*Node* cur = a;
		if (cur->left != NULL)
		{
			cur = cur->left;
			v.push_back(cur->data);
			inorder(cur);
			

		}
		else if (cur->right != NULL) {
			v.push_back(cur->data);
			inorder(cur);
			return cur;
		}
		else {
			v.push_back(cur->data);
			return cur;

		}
		return NULL;*/
		if (a->left != NULL) {
			inorder(a->left);
		}
		v.push_back(a->data);
		if (a->right != NULL) {
			inorder(a->right);
		}
		return search(v[0]);
	}
	Node* search(int data) {
		Node* curN = this->root;
		while (curN != NULL) {
			if (data == curN->data) return curN;
			else if (data > curN->data) curN = curN->right;
			else curN = curN->left;
		}
		return NULL;
	}


	void insert(int a) {
		if (root == NULL) {
			Node* node = new Node(a);
			root = node;
			
		}
		else {
			Node* curN = root;
			Node* parN = NULL;
			Node* node = new Node(a);
			while (curN != NULL) {
				if (a > curN->data) {
					parN = curN;
					curN = curN->right;
					

				}
				else if (a < curN->data) {
					parN = curN;
					curN = curN->left;
				}
			}
			if (a < parN->data) {
				parN->left = node;
				node->par = parN;
			}
			else if (a > parN->data) {
				parN->right = node;
				node->par = parN;
			}
		}
	}
};

int main() {
	BST bst;
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		if (s == "insert") {
			int a;
			cin >> a;
			bst.insert(a);

		}
		else if (s == "sub") {
			int a;
			cin >> a;
			cout << bst.sub(a) << endl;
		}
		else if (s == "delete") {
			int a;
			cin >> a;
			bst.Delete(a);
		}
	}
	return 0;
}

	