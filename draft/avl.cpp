#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
using namespace std;

// build BST first
struct Node {
	int val;
	Node* lc;
	Node* rc;

	Node(int _val) {
		val = _val;
		lc = NULL;
		rc = NULL;
	}

	Node(const Node& _node) {
		this->val = _node.val;
		if (_node.lc == NULL)
			this->lc = NULL;
		if (_node.rc == NULL)
			this->rc = NULL;
	}

	Node& operator=(const Node& rhs) {
		this->val = rhs.val;
		if (rhs.lc == NULL)
			this->lc = NULL;
		if (rhs.rc == NULL)
			this->rc = NULL;
		return *this;
	}
};

void add(list<Node>& bst, int x) {
	if (bst.empty()) {
		bst.push_back(Node(x));
		return;
	}
	Node root = bst.front();
	bool loop = true;
	while (loop) {
		if (x <= root.val) {
			if (root.lc != NULL)
				root = *root.lc;
			else {
				bst.push_back(Node(x));
				root.lc = &bst.back();
				cout << root.val << "->" << root.lc->val << endl;
				loop = false;
			}
		}
		else {
			if (root.rc != NULL)
				root = *root.rc;
			else {
				bst.push_back(Node(x));
				root.rc = &bst.back();
				cout << root.val << "->" << root.rc->val << endl;
				loop = false;
			}
		}
	}
}

void build(list<Node>& bst, vector<int> v) {
	if (v.empty())
		return;

	for (int i=0; i<(int)v.size(); i++) {
		add(bst, v[i]);
	}
}

void dfs(Node root) {
	cout << root.val << " ";
	if (root.lc != NULL)
		dfs(*root.lc);
	if (root.rc != NULL)
		dfs(*root.rc);
}

// search tree function
// either dfs or bst.search

int main() {
	// container
	list<Node> bst;
	int a[] = {5, 10, 3, 6, 14, 27, 12, 1, 4, 11, 15, 32, 13, 20, 9, 26, 75, 49, 37, 34, 18, 17, 2, 25, 40, 36};
	vector<int> v = vector<int>(a, a + sizeof(a)/sizeof(int));

	build(bst, v);
	dfs(bst.front());

	return 0;
}
