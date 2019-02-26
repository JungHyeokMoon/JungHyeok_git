#include <iostream>
#include <string>
using namespace std;

string assessment(int score) {
	if (score < 60)
		return "F";
	else if (score < 67)
		return "D";
	else if (score < 70)
		return "D+";
	else if (score < 77)
		return "C";
	else if (score < 80)
		return "C+";
	else if (score < 87)
		return "B";
	else if (score < 90)
		return "B+";
	else if (score < 97)
		return "A";
	else
		return"A+";
}

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		string s;
		int score;
		cin >> s;
		scanf("%d", &score);
		cout << s << " " << assessment(score) << endl;
	}
	return 0;
}
