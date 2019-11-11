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


int n, q;
vector <int >v;
vector<int>psum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	v.resize(n);
	psum.resize(n + 1);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	psum[0] = 0;
	for (int i = 0; i < n; i++) {
		psum[i + 1] = psum[i] + v[i];
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		printf("%d\n", psum[r] - psum[l - 1]);
	}
	

	return 0;
}