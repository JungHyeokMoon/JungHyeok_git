#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int burger[3];
int drink[2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; i++)
		cin >> burger[i];

	for (int i = 0; i < 2; i++)
		cin >> drink[i];

	int ret=987654321;
	int sum = 0;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			sum = burger[i] + drink[j] - 50;
			ret = min(ret, sum);
		}
	}

	cout << ret << "\n";

	return 0;
}