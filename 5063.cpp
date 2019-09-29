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
int r, e, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r >> e >> c;
		if (r == e - c)cout << "does not matter" << "\n";
		else if (r < e - c)cout << "advertise" << "\n";
		else cout << "do not advertise" << "\n";
	}
	
	return 0;
}	