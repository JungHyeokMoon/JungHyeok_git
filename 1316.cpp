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
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	int ret = n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		int len = input.size();
		bool vowel[26] = { false };
		int prev = 0;
		vowel[input[0] - 'a'] = true;
		for (int i = 1; i < len; i++) {
			if (vowel[input[i] - 'a'] == false) {
				vowel[input[i] - 'a'] = true;
			}
			else {
				if (input[i] != input[prev]) {
					ret--;
					break;
				}
			}
			prev++;
		}

	}

	cout << ret << "\n";
	return 0;
}	