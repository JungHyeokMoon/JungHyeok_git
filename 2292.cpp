#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <map>
#include <deque>
using namespace std;

int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	if (N == 1) {
		cout << 1 << "\n";
	}
	else {
		int num = 1;
		int cnt = 1;
		while (num + cnt * 6 < N) {
			num += cnt * 6;
			cnt++;
		}
		cout << cnt+1 << "\n";
	}
	return 0;
}	