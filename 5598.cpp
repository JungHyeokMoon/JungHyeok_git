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

string str;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> str;
	int len = str.size();
	string answer = "";

	for (int i = 0; i < len; i++) {
		if ('D' <= str[i] && str[i] <= 'Z') {
			answer+= (str[i] - 3);
		}
		else {
			if (str[i] == 'A') {
				answer += 'X';
			}
			else if (str[i] == 'B') {
				answer += 'Y';
			}
			else {
				answer += 'Z';
			}
		}
	}
	cout << answer << "\n";
	
	return 0;
}