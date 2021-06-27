#include<iostream>
#include<string> 
#include<string.h> // memset, 
#include<queue>

using namespace std;

class Node {
public:
	int data;
	Node* par;
	Node* left;
	Node* right;
};

class BST {
private:
	Node* root;
	vector <int> arr; // 순서대로 정렬할 벡터.
public:
	BST() {
		root = NULL;
	}
	void insert(int tmp) {
		Node* cur_Node = new Node();
		cur_Node->data = tmp;

		if (root == NULL) {
			root = new Node();
			root->data = tmp;
		}
		else {
			Node* par_Node = NULL;
			Node* cur_Node = root;
			while (cur_Node != NULL) {
				if (tmp > cur_Node->data) {
					par_Node = cur_Node;
					cur_Node = cur_Node->right;
				}
				else {
					par_Node = cur_Node;
					cur_Node = cur_Node->left;
				}
			}
			cur_Node = new Node();
			cur_Node->data = tmp;
			cur_Node->par = par_Node;

			if (cur_Node->data > par_Node->data) {
				par_Node->right = cur_Node;
			}
			else {
				par_Node->left = cur_Node;
			}
		}
	}
	void Inorder(Node* n) {
		if (n->left != NULL) {
			Inorder(n->left);
		}
		arr.push_back(n->data); // 다 벡터에 넣어줌.
		if (n->right != NULL) {
			Inorder(n->right);
		}
	}

	void print() {
		Inorder(root);
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		arr.clear();
		cout << endl;
	}

	Node* search(int k) {
		Node* cur_Node = root;
		while (cur_Node->data != k) {
			if (cur_Node->data < k) {
				cur_Node = cur_Node->right;
			}
			else {
				cur_Node = cur_Node->left;
			}

			if (cur_Node == NULL) {
				return cur_Node;
			}
		}
		return cur_Node;
	}

	void Delete(int k) {
		Node* d_Node = search(k);

		if (d_Node->left == NULL && d_Node->right != NULL) { // 자식 하나
			if (d_Node != root) {
				d_Node->right->par = d_Node->par;

				if (d_Node->par->left == d_Node) {
					d_Node->par->left = d_Node->right;
				}
				else {
					d_Node->par->right = d_Node->right;
				}
			}
			else {
				root = root->right;

				root->par = NULL;
			}
		}
		else if (d_Node->left != NULL && d_Node->right == NULL) { // 자식하나
			if (d_Node != root) {
				d_Node->left->par = d_Node->par;

				if (d_Node->par->left == d_Node) {
					d_Node->par->left = d_Node->left;
				}
				else {
					d_Node->par->right = d_Node->left;
				}
			}
			else {
				root = root->left;

				root->par = NULL;

			}
		}
		else if (d_Node->left == NULL && d_Node->right == NULL) { // 자식없을때
			if (d_Node != root) {
				if (d_Node->par->left == d_Node) {
					d_Node->par->left = NULL;
					d_Node->par = NULL;
				}
				else {
					d_Node->par->right = NULL;
					d_Node->par = NULL;
				}
			}
			else {
				root = NULL;
			}
		}
		else if (d_Node->left != NULL && d_Node->right != NULL) { // 자식 둘일때.
			Node* cur_Node = d_Node->right;

			while (cur_Node->left != NULL) {
				cur_Node = cur_Node->left;
			}



			if (d_Node != root) {
				if (d_Node->par->left == d_Node) { // 삭제할 노드의 자리에 cur노드를 넣음.
					d_Node->par->left = cur_Node;
				}
				else {
					d_Node->par->right = cur_Node;
				}

				if (cur_Node->right == NULL) {
					Node* temp = cur_Node;

					cur_Node->par = d_Node->par;
					d_Node->left->par = cur_Node;
					d_Node->right->par = cur_Node;
					cur_Node->left = d_Node->left;
					cur_Node->right = d_Node->right;

					if (temp->par->left == temp) {
						temp->par->left = NULL;
					}
					else {
						temp->par->right = NULL;
					}
				}
				else {
					cur_Node->par = d_Node->par;
					d_Node->left->par = cur_Node;
					cur_Node->left = d_Node->left;
				}
			}
			else {
				if (cur_Node->right == NULL) {
					Node* temp = cur_Node;

					d_Node->left->par = cur_Node;
					d_Node->right->par = cur_Node;
					cur_Node->left = d_Node->left;
					cur_Node->right = d_Node->right;
					root = cur_Node;

					root->par = NULL;
					if (temp->par->left == temp) {
						temp->par->left = NULL;
					}
					else {
						temp->par->right = NULL;
					}
				}
				else {
					d_Node->left->par = cur_Node;
					cur_Node->left = d_Node->left;
					root = cur_Node;

					root->par = NULL;
				}
			}


		}
	}

	void sub(int k) {
		Node* cur_Node = search(k);
		if (cur_Node == NULL) {
			cout << 0 << endl;
			return;
		}
		Inorder(cur_Node);
		cout << arr.size() << endl;
		arr.clear();
	}


};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	BST minje;
	while (testCase--) {
		string s;
		cin >> s;
		if (s == "insert") {
			int tmp;
			cin >> tmp;
			minje.insert(tmp);
		}
		else if (s == "delete") {
			int tmp;
			cin >> tmp;
			minje.Delete(tmp);
		}
		else if (s == "sub") {
			int tmp;
			cin >> tmp;
			minje.sub(tmp);
		}
		else if (s == "print") {
			minje.print();
		}

	}
}

