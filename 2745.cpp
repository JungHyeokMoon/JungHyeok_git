#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	int N = 0;
	int B;

	cin >> s;
	scanf("%d", &B);
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if ('0'<=s[i]&&s[i]<='9') {// 10진법일경우
			N = N * B + (s[i] - '0');
		}
		else {//넘어갈경우
			N = N * B + (s[i] - 'A'+10);
		}
	}

	cout << N << endl;

	return 0;
}