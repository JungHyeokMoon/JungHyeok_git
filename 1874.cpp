#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int n;
const int MAX = 100000;
int arr[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<char> op;
	stack<int> stk;
	int num = 0;
	for (int i = 0; i < n; i++) {
		while (1) {
			if (num >= arr[i])
				break;
			else {
				stk.push(++num);
				op.push_back('+');
			}
		}
		if (arr[i] == stk.top()) {
			stk.pop();
			op.push_back('-');
		}
		else if (arr[i] < stk.top()) {
			cout << "NO" << "\n";
			return 0;
		}

	}
	
	int len = op.size();
	for (int i = 0; i < len; i++) {
		cout << op[i] << "\n";
	}
	
	
	return 0;
}