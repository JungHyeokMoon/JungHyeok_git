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

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		vector<pair<int, int>>fibo(41);
		fibo[0].first = 1, fibo[0].second = 0;
		fibo[1].first = 0, fibo[1].second = 1;
		for (int i = 2; i <= num; i++) {
			fibo[i].first = fibo[i - 1].first + fibo[i - 2].first;
			fibo[i].second = fibo[i - 1].second + fibo[i - 2].second;
		}
		cout << fibo[num].first << " " << fibo[num].second << "\n";
	}
	
	
	return 0;
}