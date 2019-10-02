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
string A, B;
const int MAX = 30;
char arr[MAX][MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;
	int n = A.size();
	int m = B.size();
	int i = 0, j = 0;
	bool flag = false;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (A[i] == B[j]) {
				flag = true;
				break;
				
			}
		}
		if (flag)break;
	}

	for (int k = 0; k < m; k++) {
		for (int l = 0; l < n; l++) {
			arr[k][l] = '.';
		}
	}

	

	for (int k = 0; k < m; k++) {
		for (int l = 0; l < n; l++) {
			
			if (l == i) {
				arr[k][l] = B[k];
			}
			if (k == j) {
				arr[j][l] = A[l];
			}
		}
	}

	for (int k = 0; k < m; k++) {
		for (int l = 0; l < n; l++) {
			cout << arr[k][l];
		}
		cout << "\n";
	}
	

	
	return 0;
}	

