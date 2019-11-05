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
int n;
int arr[1024][1024];
vector<int> v;

void solve(int y, int x, int length) {
	
	if(length==2) {
		v[0] = arr[y][x];
		v[1] = arr[y + 1][x];
		v[2] = arr[y][x + 1];
		v[3] = arr[y + 1][x + 1];
		sort(v.begin(), v.end());
		arr[y/2][x/2] = v[2];
		
	}
	else  {
		solve(y, x, length / 2);
		solve(y, x + length / 2, length / 2);
		solve(y + length / 2, x, length / 2);
		solve(y + length / 2, x + length / 2, length / 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	v.resize(4);
	int cnt = 0;
	int length = n;
	while (n != 1) {
		n /= 2;
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		solve(0, 0, length);
	}

	printf("%d\n", arr[0][0]);


	
	

}