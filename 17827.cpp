#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <map>
#include <deque>
using namespace std;

typedef struct node {
	int key;
	node* next;
}node;

int n, m, v;
node* nodearr;
node* latest;
void init() {
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			nodearr[i].next = &nodearr[i + 1];
		}
		else {
			nodearr[i].next = &nodearr[v - 1];
		}
	}
	latest = &nodearr[v - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d %d %d", &n, &m, &v);
	nodearr = (node *)malloc(sizeof(node) * n);
	init();
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		nodearr[i].key = num;
	}

	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		if (k <= n) {
			printf("%d\n", nodearr[k - 1].next->key);
		}
		else {
			int iter = (k - n) % (n - v + 1);
			node* ret = latest;
			for (int i = 0; i < iter; i++) {
				ret = ret->next;
			}
			printf("%d\n", ret->key);
		}
	}

	
}