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
using namespace std;
string input;

string croatia_alphabet[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input;
	int len = input.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 8; j++) {
			if (input.find(croatia_alphabet[j]) != string::npos) {
				int k = 0;

				k = input.find(croatia_alphabet[j]);

				input.erase(k, croatia_alphabet[j].length());
				input.insert(k, "*");
			}
		}
	}
	cout << input.size() << "\n";
	return 0;
}