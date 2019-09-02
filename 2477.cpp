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
using namespace std;

int k = 0;
int maxarea = 0;
int minarea = 0;
int dir;
int x[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	int j;
	for (int i = 0; i < 6; i++) {
		cin >> dir >> x[i];
	}
	for (int i = 0; i < 6; i++) {
		
		if (maxarea < x[i] * x[(i+1) % 6]) {
			maxarea = x[i] * x[(i+1) % 6];
			j = i;
		}
	}
	minarea = x[(j + 3) % 6] * x[(j + 4) % 6];
	cout << (maxarea - minarea)*k << "\n";


	
	
	return 0;
}