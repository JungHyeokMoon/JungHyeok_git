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

int n, m;

const int MAX = 500000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<string> listen(n);
	vector<string> see(m);

	for (int i = 0; i < n; i++) {
		cin >> listen[i];
	}
	sort(listen.begin(), listen.end());


	vector<string> answer;
	for (int i = 0; i < m; i++) {
		cin >> see[i];
		if (binary_search(listen.begin(), listen.end(), see[i])) {
			answer.push_back(see[i]);
		}
	}

	sort(answer.begin(), answer.end());

	int len = answer.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}