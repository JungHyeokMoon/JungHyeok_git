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

int x, y, w, h;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y >> w >> h;

	int ret = 987654321;
	ret = min(x, ret);
	ret = min(w - x, ret);
	ret = min(y, ret);
	ret = min(h - y, ret);

	cout << ret << "\n";

	return 0;
}