#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v(3);

	for (int i = 0; i < 3; i++)
		cin >> v[i].first >> v[i].second;

	int op = v[0].first * v[1].second + v[1].first * v[2].second + v[2].first * v[0].second;
	op -= v[1].first * v[0].second + v[2].first * v[1].second + v[0].first * v[2].second;

	if (op == 0)cout << 0 << "\n";
	else if (op > 0) cout << 1 << "\n";
	else cout << -1 << "\n";

	return 0;
}