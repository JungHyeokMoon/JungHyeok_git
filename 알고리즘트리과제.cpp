#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
int cnt = 0;
class binarynode {
public:
	int index;
	binarynode * left;
	binarynode * right;
	binarynode(int i = 0, binarynode *l = NULL, binarynode *r = NULL) :index(i), left(l), right(r){};
	
};
class binarytree {
public:
	binarynode *root;
	binarytree():root(NULL){}
	void setRoot(binarynode *node){
		root = node;
	}
	int getCount(binarynode *node) {
		if (node == NULL)
			return 0;
		else {
			return 1 + getCount(node->left) + getCount(node->right);
		}
	}
	

	void preorderadd(binarynode *root, int nodeindex, int left, int right) {
		if (!root) {
			return;
		}
		else if (root->index == nodeindex) {
			if (left != -1)root->left = new binarynode(left, NULL, NULL);
			if (right != -1)root->right = new binarynode(right, NULL, NULL);
		}
		else {
			preorderadd(root->left, nodeindex, left, right);
			preorderadd(root->right, nodeindex, left, right);
		}
	}

	void add(int nodeindex, int left, int right) {
		if (!root) {
			root = new binarynode(nodeindex, NULL, NULL);
			if (left != -1)root->left = new binarynode(left, NULL, NULL);
			if (right != -1)root->right = new binarynode(right, NULL, NULL);
		}
		else {
			preorderadd(root, nodeindex, left, right);
		}
	}

	void deletetree(binarynode *node) {
		if (!node)
			return;
		else {
			deletetree(node->left);
			deletetree(node->right);
			delete node;
		}
	}

	void postorderanswer(binarynode *node) {
		if (!node)
			return;
		else {
			postorderanswer(node->left);
			postorderanswer(node->right);
			if (getCount(node->left) < getCount(node->right)) cnt++;
		}
	}


};

int main() {
	int testnumber;
	int nodenumber;
	int nodeindex, l, r;
	FILE *f = fopen("input.txt", "r");


	fscanf(f,"%d", &testnumber);
	while (testnumber--) {
		fscanf(f, "%d", &nodenumber);

		binarytree tree;
		for (int i = 1; i <= nodenumber; i++) {
			fscanf(f, "%d %d %d", &nodeindex, &l, &r);
			tree.add(nodeindex, l, r);
		} // 트리연결

		tree.postorderanswer(tree.root);
		printf("%d\n",cnt);
		tree.deletetree(tree.root);
		
		cnt = 0;
	}
	
	fclose(f);
	return 0;
}

