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
string str;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		getline(cin, str);
		if (str == "END")
			break;
		int len = str.size();
		for (int i = len - 1; i >= 0; i--)
			cout << str[i];
		cout << "\n";

	}
	
	
	return 0;
}