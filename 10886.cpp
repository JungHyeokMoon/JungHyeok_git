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
const int MAX = 2200;
int n;
int arr[102];
int zerocnt = 0;
int onecnt = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >>  arr[i];
		if (arr[i] == 0) {
			zerocnt++;
		}
		else {
			onecnt++;
		}
		
	}
	if (zerocnt > onecnt) {
		cout << "Junhee is not cute!" << endl;
	}
	else {
		cout << "Junhee is cute!" << endl;
	}


	return 0;
}




