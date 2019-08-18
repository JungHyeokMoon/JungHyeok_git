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
const int MAX = 100;
int arr[MAX + 1];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int ret = 0;
	int diff = 0;
	for (int i = n-1; i>0; i--){
		if (arr[i] <= arr[i - 1]) {
			diff = arr[i-1] - arr[i] + 1;
			arr[i - 1] = arr[i - 1] - diff;
			ret += diff;
		}
	}
	
	cout << ret << "\n";
	return 0;
}