#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int d, k; //d : day k : 떡의갯수
int fibo[31];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> d >> k;

	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i <= d; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	for (int i = 1; i <= k; i++) {
		for (int j = i; j <= k; j++) {
			if (i*fibo[d - 2] + j * fibo[d - 1] == k) {
				cout << i << endl << j << endl;
				return 0;
			}
			else if (k < i*fibo[d - 2] + j * fibo[d - 1]) {
				break;
			}
		}
	}

}