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

int n, m;
const int MAX = 100000;
//int arr[MAX];
int A;
int psum[MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	psum[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> A;
		psum[i + 1] = psum[i] + A;
	}


	int a, b;
	int idx1, idx2;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		idx2 = max(a, b);
		idx1 = min(a, b);
		cout << psum[idx2] - psum[idx1 - 1] << "\n";
	}




	return 0;
}