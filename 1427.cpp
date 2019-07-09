#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int n;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n != 0) {
		int a = n % 10;
		v.push_back(a);
		n = n / 10;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int len = v.size();
	for (int i = 0; i < len; i++) {
		cout << v[i];
	}
	return 0;
}
