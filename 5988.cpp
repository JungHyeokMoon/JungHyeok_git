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
		if ((s[len - 1] - '0') % 2 == 0)
			printf("even\n");
		else
			printf("odd\n");
	}

	return 0;
}
