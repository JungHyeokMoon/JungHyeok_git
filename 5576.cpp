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
vector<int> w(10);
vector<int> k(10);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0; i < 10; i++)
		cin >> w[i];
	for (int i = 0; i < 10; i++)
		cin >> k[i];
	sort(w.begin(), w.end());
	sort(k.begin(), k.end());
	int sum1 = 0, sum2 = 0;
	sum1 = w[7] + w[8] + w[9];
	sum2 = k[7] + k[8] + k[9];

	cout << sum1 << " " << sum2 << "\n";

	return 0;
}