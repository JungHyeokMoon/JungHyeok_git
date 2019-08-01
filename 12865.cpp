#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int t;
const int MAX = 101;
int n, k;
 //first 물건의무게 w 물건의가치 w
int dp[101][100001];
vector<pair<int, int>> item;


int solve(int pos, int capacity) {

	if (capacity < 0) return -987654321;
	if (pos == n|| capacity==0)return 0;

	if (dp[pos][capacity] != -1)return dp[pos][capacity];
	
	return dp[pos][capacity] = max(solve(pos + 1, capacity), solve(pos + 1, capacity - item[pos].first) + item[pos].second);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	
	cin >> n >> k;
	item.resize(n + 1);
	//
	fill(dp[0], dp[n+1], -1);
	for (int i = 0; i < n; i++) {
		int wei, val;
		cin >> wei >> val;
		item[i] = make_pair(wei, val);
	}
	cout << solve(0, k) << "\n";
	return 0;
}