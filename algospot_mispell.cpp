#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int n, m;
string str;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m >> str;
		string answer = "";
		int len = str.size();
		for (int i = 0; i < len; i++) {
			if (i == m - 1)continue;
			answer += str[i];
		}

		cout << i + 1 << " " << answer << endl;
	}
	
	return 0;
}