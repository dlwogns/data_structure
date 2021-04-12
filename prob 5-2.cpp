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
		iterator(Node* u) {
			v = u;
		}
	public:
		int& operator*() {
			return v->e;
		}
		bool operator==(const iterator& p)const {
			return v == p.v;
		}
		bool operator!=(const iterator& p)const {
			return v != p.v;
		}
		iterator& operator++() {
			v = v->next;
			return *this;
		}
		iterator& operator--() {
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
	SequenceList() {
		n = 0;
		header = new Node;
		header->e = 0;
		trailer = new Node;
		trailer->e = 0;
		header->next = trailer;
		trailer->prev = header;
	}
	void insert(int a) {
		if (this->empty()) {
			Node* nN = new Node;
			nN->e = a;
			header->next = nN;
			nN->prev = header;
			nN->next = trailer;
			trailer->prev = nN;

		}
		else {
			Node* l = trailer->prev;
			Node* nN = new Node;
			nN->e = a;
			nN->next = trailer;
			trailer->prev = nN;
			nN->prev = l;
			l->next = nN;
		}
		n++;
	};
	int size() {
		return n;
	}
	bool empty() {
		return n == 0;
	}
	iterator begin();
	iterator end();
};
SequenceList::iterator SequenceList::begin()
{
	return iterator(header->next);
}
SequenceList::iterator SequenceList::end() {
	return iterator(trailer);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		SequenceList sl;
		
		while (a--) {
			int inputnum;
			cin >> inputnum;
			sl.insert(inputnum);
		}
		SequenceList::iterator iter = sl.begin();
		while (iter != sl.end()) {

			int max = *iter;
			SequenceList::iterator i1 = --iter;
			++iter;
			SequenceList::iterator i2 = ++iter;
			--iter;
			if (max < *i1) max = *i1;
			if (max < *i2) max = *i2;
			cout << max << ' ';
			++iter;
		}
		cout << endl;
	}

}

