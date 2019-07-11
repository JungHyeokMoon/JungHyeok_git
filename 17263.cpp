#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 500001;
int n;
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + n);
	cout << arr[n];
	return 0;
}




