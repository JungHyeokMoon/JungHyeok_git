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

int n;
int A[50];
int B[50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
		cin >> B[i];

	sort(A, A + n);
	sort(B, B + n);
	reverse(B, B + n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i] * B[i];
	}
	
	cout << sum << "\n";
	
	return 0;
}