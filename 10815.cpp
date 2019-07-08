#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 500001;
int n;
int m;
int input[MAX];
int arr[MAX];
void binary_search(int l, int r,int key) {
	
	if (l > r) {
		cout << "0" << " ";
		return;
	}
	int mid = (l + r) / 2;
	if (input[mid] == key) {
		cout << "1" << " ";
		return;
	}
	else if (input[mid] < key) {
		
		binary_search(mid+1, r, key);
	}
	else { //input[mid]>key
		binary_search(l,mid - 1, key);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		
	}
	for (int i = 0; i < m; i++) {
		binary_search(0, n, arr[i]);
	}
	
	

	return 0;
}
