#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;
int n;
vector<int> v1(4, 0);
vector<int> v2(4, 0);
int sum1 = 0;
int sum2 = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0; i < 4; i++) {
		cin >> v1[i];
		sum1 += v1[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> v2[i];
		sum2 += v2[i];
	}
	int ret = max(sum1, sum2);
	cout << ret << "\n";

	return 0;
}