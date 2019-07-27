#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


vector<char> even;
vector<char> odd;
string str;
int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> str;
		int len = str.size();

		for (int i = 0; i < len; i++) {
			if (i == 0 || i % 2 == 0) {
				even.push_back(str[i]);
			}
			else {
				odd.push_back(str[i]);
			}
		}
		for (int i = 0; i < even.size(); i++) {
			cout << even[i];
		}
		for (int i = 0; i < odd.size(); i++) {
			cout << odd[i];
		}
		cout << endl;
		even.clear();
		odd.clear();
	}
	return 0;
}

