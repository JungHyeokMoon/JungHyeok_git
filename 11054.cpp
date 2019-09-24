#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1001;
int arr[MAX];
int dp1[MAX];
int dp2[MAX];
int n;

int solve1(int idx1) {
	
	int& ret = dp1[idx1];
	if (ret != -1)return ret;

	ret = 1;
	for (int i = idx1 + 1; i < n; i++) {
		if (arr[idx1] > arr[i])
			ret = max(ret, solve1(i) + 1);
	}

	return ret;
}

int solve2(int idx2) {
	

	int& ret = dp2[idx2];
	if (ret != -1)return ret;

	ret = 1;
	for (int i = idx2 - 1; i >= 0; i--) {
		if (arr[idx2] > arr[i])
			ret = max(ret, solve2(i) + 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));

	int ret = -987654321;
	for (int i = 0; i < n; i++) {
		ret = max(ret, solve1(i) + solve2(i));
	}

	cout << ret-1<< "\n";
	

	
	return 0;
}