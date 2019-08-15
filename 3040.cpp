#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;


vector<int> v;
vector<int> answer;
int sum = 0;
bool chk[9];
int ret = 0;
void solve(int num) {
		if(sum==100 && answer.size()==7)
		{
			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i] << "\n";
			}
			exit(0);
		}

		if(answer.size()==7)
		return;

	for (int i = num; i < 9; i++) {
		if (!chk[i]) {
			answer.push_back(v[i]);
			sum += v[i];
			chk[i] = true;
			solve(i + 1);
			sum -= v[i];
			chk[i] = false;
			answer.pop_back();
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.resize(9);

	for (int i = 0; i < 9; i++)
		cin >> v[i];

	solve(0);

	return 0;
}