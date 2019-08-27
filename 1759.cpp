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

int l, c;
char input[15];
char ret[16];
bool isvowel[26];

void password(int pos, int prev, int consonant,int vowel) {
	if (pos == l) {
		if (consonant >= 2 && vowel >= 1) {
			for (int i = 0; i < l; i++) {
				cout << ret[i];
			}
			cout << "\n";
			return ;
		}
	}

	for (int i = prev + 1; i < c; i++) {
		ret[pos] = input[i];
		password(pos + 1, i, consonant + !isvowel[input[i] - 'a'], vowel + isvowel[input[i] - 'a']);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> input[i];
	sort(input, input + c);
	isvowel[0] = isvowel[4] = isvowel[8] = isvowel[14] = isvowel[20] = true;
	password(0, -1, 0, 0);

	return 0;
}
//블로그참고해서풀었음 , 모음 처리하는방법과 백트랙킹