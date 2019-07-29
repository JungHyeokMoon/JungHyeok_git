#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
const int N = 28;
bool arr[31];
int num;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num] = true;
	}
	for (int i = 1; i < 31; i++) {
		if (!arr[i]) cout << i << endl;
	}
	return 0;
}



