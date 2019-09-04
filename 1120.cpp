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

string A, B;
int front = 0;
int rear = 0;
int ret = 987654321;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	int diff = B.size() - A.size();
	
	for (int i = 0; i <= diff; i++) {
		int mini = 0;
		for (int j = 0; j < A.size(); j++) {
			if (A[j] != B[j + i])
				mini++;
		}
		ret = min(ret, mini);
	}
	cout << ret << "\n";
	
	
	return 0;
}