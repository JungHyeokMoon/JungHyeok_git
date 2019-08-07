#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int n, s;

vector<int> v;
int ret = 0;

void dfs(int num, int pos) {
	if (pos == n)
		return;
	if (num+v[pos] == s)
		ret++;

	dfs(num , pos + 1);
	dfs(num + v[pos], pos + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> n >> s;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dfs(0, 0);
	cout << ret << endl;
	return 0;

}