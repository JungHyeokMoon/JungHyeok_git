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
const int MAX = 1000;
int arr[MAX + 1];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//if(arr[j]>=arr[j+1]){ret=max(ret,arr[j]-arr[i], i=j+1; break;}
	//8 12 3 5 7 10 6 1 11
	int ret = 1;
	for (int i = 0; i < n-1; i++) {
		for (int j = i; j < n-1; j++) {
			if (j + 1 == n - 1) {
				if(arr[j+1]>arr[j])
				ret = max(ret, arr[j + 1] - arr[i]);
			}
			if (arr[j] >= arr[j + 1]) {
					ret = max(ret, arr[j] - arr[i]);
					i = j;
					break;
				
			}
		}
	}
	if (ret == 1) {
		cout << 0 << "\n";
	}
	else {
		cout << ret << "\n";
	}
	return 0;
}