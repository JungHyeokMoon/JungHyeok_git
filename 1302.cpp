#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

map<string, int > mp;
int n;
string str;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		mp[str]++;
	}
	int max = 0;
	string answer;
	for (auto i = mp.begin(); i != mp.end(); i++) {
		if (max < i->second) {
			max = i->second;
			answer = i->first;
		}
	}
	cout << answer << endl;
	
	return 0;
}



