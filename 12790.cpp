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
int n;
int firstHP, firstMP, firstAttack, firstDefense, secondHP, secondMP, secondAttak, secondDefense;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> firstHP >> firstMP >> firstAttack >> firstDefense >> secondHP >> secondMP >> secondAttak >> secondDefense;
		int hp = (firstHP + secondHP) < 1 ? 1 : firstHP + secondHP;
		int mp = (firstMP + secondMP) < 1 ? 1 : firstMP + secondMP;
		int attack = (firstAttack + secondAttak) < 0 ? 0 : firstAttack + secondAttak;
		int defense = firstDefense + secondDefense;
		int stat = hp + 5 * mp + 2 * attack + 2 * defense;
		cout << stat << "\n";
	}
	
	
	return 0;
}	