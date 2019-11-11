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
int n, m; //약속의개수 방학의일자
const int MAX = 1000;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	//n개의 약속이있으면 최대 n+1개의 빈공간이생김 빈공간이 최대한 많이남아야지 덜우울해진다 왜냐하면 우울함이지속될수록 기분^2이 우울함에더해지니깐
	for (int i = 0; i < n; i++) {
		int mood;
		cin >> mood;
		m -= (mood+1);
	}
	if (m <= 0) { cout << 0 << "\n"; } //m이 0이하면우울한날이없다.
	else {
		int q = m / (n + 1);
		int r = m % (n + 1);
		int ret = 0;
		for (int j = 0; j < n + 1; j++) {
			int val;
			if (j < r) {
				val = q + 1; //r개
			}
			else {
				val = q; //n+1-r개
			}
			ret += (val * (val + 1) * (2 * val + 1)) / 6;
		}
		cout << ret << "\n";
	}


	return 0;
}