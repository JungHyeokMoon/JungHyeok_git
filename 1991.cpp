#include <iostream>
#include <algorithm>
using namespace std;
class treeNode {
public:
	char data;
	treeNode * left;
	treeNode *right;
	treeNode(char d='.', treeNode* l=NULL, treeNode * r=NULL) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class tree {
public:
	treeNode* root;
	tree() :root(NULL) {}

	void search(treeNode* node, char rt, char l, char r) {
		if (node == NULL)
			return;
		else if (node->data == rt) {
			if (l != '.')node->left = new treeNode(l, NULL, NULL);
			if (r != '.')node->right = new treeNode(r, NULL, NULL);
		}
		else {
			search(node->left, rt, l, r);
			search(node->right, rt, l, r);
		}
	}
	void addnode(char rt, char l, char r) {
		if (root == NULL) {
			root = new treeNode(rt, NULL, NULL);
			if (l != '.') {
				root->left = new treeNode(l, NULL, NULL);
			}
			if (r != '.') {
				root->right = new treeNode(r, NULL, NULL);
			}
		}
		else search(root, rt, l, r);
	}

	void preorder(treeNode* node) {
		if (node!=NULL) {
			cout << node->data;
			preorder(node->left);
			preorder(node->right);
		}
	}
	void inorder(treeNode* node) {
		if (node!=NULL) {
			inorder(node->left);
			cout << node->data;
			inorder(node->right);
		}
	}
	void postorder(treeNode* node) {
		if (node!=NULL) {
			postorder(node->left);
			postorder(node->right);
			cout << node->data;
		}
	}
};

int N;
char root, l, r;
int main() {
	tree t;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> root >> l >> r;
		t.addnode(root, l, r);
	}
	t.preorder(t.root), cout << endl;
	t.inorder(t.root), cout << endl;
	t.postorder(t.root), cout << endl;

	return 0;
	

}