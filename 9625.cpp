#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

const int	MAX = 46;
int arr[MAX];
int k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr[0] = 1;
	arr[1] = 1;
	
	cin >> k;

	for (int i = 2; i <= k; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[k - 2] <<" "<<arr[k - 1] << "\n";
	return 0;
}