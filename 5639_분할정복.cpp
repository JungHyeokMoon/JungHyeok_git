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

const int MAX = 10000;
int arr[MAX + 1];
int n;

void print(int l, int r) {
	if (l > r) return;
	int s = l;
	int e = r;
	int root = l;
	while (arr[s] >= arr[root])s++;
	while (arr[e] > arr[root])e--;
	print(s, e);
	print(e + 1, r);
	cout << arr[root] << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	while (scanf("%d", &num) != EOF) {
		arr[n++] = num;
	}
	print(0, n - 1);

	return 0;
}