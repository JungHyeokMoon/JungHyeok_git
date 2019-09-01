#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <stack>
using namespace std;

class binarynode {
private:
	int key;
	binarynode * left;
	binarynode * right;

public:
	binarynode(int k = 0, binarynode *l = NULL, binarynode *r = NULL) {
		key = k;
		left = l;
		right = r;
	}
	int getkey() {
		return key;
	}
	binarynode * getleft() {
		return left;
	}
	binarynode * getright() {
		return right;
	}
	void setleft(binarynode *l) {
		left = l;
	}
	void setright(binarynode *r) {
		right = r;
	}
};

class binarysearchtree {
private:
	binarynode * root;

public:
	binarysearchtree() {
		root = NULL;
	}
	binarynode * getroot() {
		return root;
	}
	void insertnode(int key) {
		binarynode *p, *t, *z;
		p = NULL;
		t = this->root;
		while (t != NULL) {
			p = t;
			if (key < p->getkey()) {
				t = p->getleft();
			}
			else {
				t = p->getright();
			}
		}
		z = new binarynode(key);
		if (p == NULL)root = z;
		else if (key < p->getkey()) {
			p->setleft( z);
		}
		else
			p->setright(z);
	}
	void postorder(binarynode *root) {
		if (root != NULL) {
			postorder(root->getleft());
			postorder(root->getright());
			cout << root->getkey() << "\n";
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	binarysearchtree * tree = new binarysearchtree;
	while (scanf("%d", &num) != EOF) {
		tree->insertnode(num);
	}
	tree->postorder(tree->getroot());


	return 0;
}