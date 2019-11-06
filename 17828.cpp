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

//ABCDEFGHIJKLMNOPQRSTUVWXYZ

int n, x;
//char arr[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d %d", &n, &x);

	if (n > x) {
		printf("!\n");
	}
	else if (n * 26 < x) {
		printf("!\n");
	}
	else {
		string answer = "";
		int temp = 1;
		for (int i = n; i >= 1; i--) {
			if (i != 1) {
				if ((i - 1) * 26 > x) {
					answer += 'A';
					x = x - 1;
				}
				else {
					while ((i - 1) * 26 != x - temp) {
						temp++;
					}
					answer += char(temp - 1 + 65);
					x = x - temp;
				}
			}
			else {
				answer += char(x - 1 + 65);
			}
		}
		cout << answer << "\n";
	}


	return 0;
}