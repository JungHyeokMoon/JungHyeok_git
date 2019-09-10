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

string input;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> input;
	int len = input.size();
	string answer = "";
	for (int i = 0; i < len; i++) {
		char temp = input[i];
		if ('A' <= temp && temp <= 'Z')
			answer += temp;
	}

	cout << answer << "\n";

	return 0;
}