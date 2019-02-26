#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		string s;
		cin >> s;
		int len = s.size();
		int ans = 0;
		for (int i = 0; i < len; i++) {
			ans = ans * 2 + (s[i]-'0');
		}
		printf("%d\n", ans);
	}

	return 0;
}