#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <math.h>
using namespace std;
int t, n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		
		int a, b;
		
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
		}
		cout << n - 1 << endl;
		
	}
	return 0;
}




