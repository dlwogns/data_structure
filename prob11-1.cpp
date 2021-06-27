#include <iostream>;
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
	int cnum = 0;
	Node* root;
	BST() {
		this->root = NULL;
	}
	int inorder(Node* a, int n) {
		Node* cur = a;
		if (cur->left != NULL)
		{
			cur = cur->left;
			inorder(cur,n);

		}
		else if(cur->right != NULL){
			if (cur->checked != 1) {
				cnum++;
				if (cnum == n)
					return cur->data;
			}
			cur->checked = 1;
			cur = cur->right;
			inorder(cur,n);
		}
		else {
			if (cur == cur->par->left) {
				if (cur->checked != 1) {
					cnum++;
					if (cnum == n)
						return cur->data;
				}
				
				cur->checked = 1;
				cur = cur->par;
				cur->setLeft(NULL);
				inorder(cur, n);
			}
			else if(cur==cur->par->right)
			{
				if (cur->checked != 1) {
					cnum++;
					if (cnum == n)
						return cur->data;
				}
				cur->checked = 1;
				cur = cur->par;
				cur->setRight(NULL);
				inorder(cur, n);
			}
			
		}
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

	int T;
	cin >> T;
	while (T--) {
		BST bst;
		int a;
		cin >> a;
		while (a--) {
			int b;
			cin >> b;
			bst.insert(b);
		}
		int c;
		cin >> c;
		cout << bst.inorder(bst.root, c) << endl;;
	}
}