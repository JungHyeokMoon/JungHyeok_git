#include <iostream>
#include <string>
using namespace std;

char cnv[] = { 'A','E','I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
int main() {
	int s;
	scanf("%d\n", &s);

	while (s--) {
		string str;
		getline(cin, str);
		int len = str.size();
		int consonanats = 0;
		int vowels = 0;
		int space = 0;
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (str[i] == cnv[j])
					vowels++;
			}
			if (str[i] == ' ')
				space++;
		}
		consonanats = len - (vowels + space);

		printf("%d %d\n", consonanats, vowels);

	}
	return 0;
}
