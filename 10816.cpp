#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
int card;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n;
	vector<int> input;
	input.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> card;
		cout << upper_bound(input.begin(), input.end(), card) - lower_bound(input.begin(), input.end(), card) << " ";
	}
	cout << "\n";
	return 0;
}



