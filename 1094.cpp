#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <functional>


using namespace std;
int x;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> x;
	
	while (x != 0) {
		if (x % 2 == 1)cnt++;
		x = x / 2;
	}
	cout << cnt << endl;
	return 0;
	
}
