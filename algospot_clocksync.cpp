#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 9999, SWITCHES = 10, CLOSKCS = 16;
int c;
const char linked[SWITCHES][CLOSKCS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x..",

};

bool aligned(const vector<int>& clocks) {
	bool ok = true;
	for (int i = 0; i < clocks.size(); i++) {
		if (clocks[i] != 12) {
			ok = false;	
			break;
		}
	}
	return ok;
}

void push(vector<int> & clocks, int swtch) {
	for (int i = 0; i < CLOSKCS; i++) {
		if (linked[swtch][i] == 'x') {
			clocks[i] += 3;
			if (clocks[i] == 15) clocks[i] = 3;
		}
	}
}
int solve(vector<int> &clocks, int swtch) {
	if (swtch == SWITCHES) return aligned(clocks) ? 0 : INF;
	int ret = INF;
	
	for (int i = 0; i < 4; i++) {
		ret = min(ret, i+solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> c;
	for (int i = 0; i < c; i++) {
		vector<int> clocks(16, 0);
		for (int i = 0; i < 16; i++) {
			cin >> clocks[i];
		}
		int ans = solve(clocks, 0);
		if (ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}


