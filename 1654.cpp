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

int k, n;
const int MAX = 10000;
int lan[MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;
	long long lo = 1;
	long long hi = 0;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		if (hi < lan[i])
			hi = lan[i];
	}

	
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < k; i++) {
			sum += (lan[i] / mid);
			if (sum > n)break;
		}
		
		if (sum < n) hi = mid-1;
		else lo = mid+1;
	}
	cout << hi << "\n";

	
	return 0;
}