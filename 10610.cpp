#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
string num;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num;
	int len = num.size();
	priority_queue<int> pq;
	int sum = 0;
	int zerocount = 0;
	for (int i = 0; i < len; i++) {
		int temp = num[i] - '0';
		sum += temp;
		if (temp == 0)zerocount++;
		pq.push(temp);
	}

	if (!(zerocount != 0 && sum % 3 == 0)) {
		cout << -1 << "\n";
		return 0;
	}

	string answer = "";
	while (!pq.empty()) {
		answer += (pq.top()+'0');
		pq.pop();
	}

	cout << answer << "\n";
	
	return 0;
}