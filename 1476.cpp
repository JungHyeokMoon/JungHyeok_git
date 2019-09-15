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

int e, s, m;
int init_e = 1, init_s = 1, init_m = 1;
int cnt = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> e >> s >> m;
	while (1) {
		if (init_e == e && init_s == s && init_m == m)
			break;
		init_e++;
		init_s++;
		init_m++;
		cnt++;
		if (init_e == 16)init_e = 1;
		if (init_s == 29)init_s = 1;
		if (init_m == 20)init_m = 1;

		
	}

	cout << cnt << "\n";



	return 0;
}