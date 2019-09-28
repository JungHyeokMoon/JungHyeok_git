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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input;
	int len = input.size();
	int i = 0;
	int ret = 0;
	for (unsigned i = 0; i < input.size(); i++) {
		if (input[i] == 'c') {
			if (input[i + 1] == '=' || input[i + 1] == '-') {
				i = i + 1;
				
			}
		}
		else if (input[i] == 'd') {
			if (input[i + 1] == '-') {
				i = i + 1;
				
			}
			else if (input[i + 1] == 'z' && input[i + 2] == '=') {
				i = i + 2;
				
			}
		}
		else if (input[i] == 'l') {
			if (input[i + 1] == 'j') {
				i = i + 1;
				
			}
		}
		else if (input[i] == 'n') {
			if (input[i + 1] == 'j') {
				i = i + 1;
				
			}
		}
		else if (input[i] == 's') {
			if (input[i + 1] == '=') {
				i = i + 1;
				
			}
		}
		else if (input[i] == 'z') {
			if (input[i + 1] == '=') {
				i = i + 1;
				
			}
		}
		ret++;
	}


	cout << ret << "\n";
	return 0;
}	