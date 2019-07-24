#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n;
const int MAX = 101;
char arr[MAX];
int c;
string sanguen = "ABC";
string chanyoung = "BABC";
string hyungin = "CCAABB";
string A = "Adrian";
string B = "Bruno";
string C = "Goran";
typedef struct Data {
	int score;
	string name;
}Data;
Data person[3];
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n;
	string str;
	cin >> str;

	int len1 = str.size();
	person[0].name = A;
	person[1].name = B;
	person[2].name = C;

	int len2 = sanguen.size();
	int len3 = chanyoung.size();
	int len4 = hyungin.size();

	int cnt1 = 0;
	for (int i = 0; i < len1; i = i + 3) {
		for (int j = 0; j < len2 && i + j < len1; j++) {
			if (str[i + j] == sanguen[j])cnt1++;
		}
	}
	
	person[0].score = cnt1;

	int cnt2 = 0;
	for (int i = 0; i < len1; i=i+4) {
		for (int j = 0; j < len3 && i+j<len1; j++) {
			if (str[i + j] == chanyoung[j]) cnt2++;
		}
	}
	person[1].score = cnt2;
	int cnt3 = 0;
	for (int i = 0; i < len1; i = i + 6) {
		for (int j = 0; j < len4 && i + j < len1; j++) {
			if (str[i + j] == hyungin[j]) {
				cnt3++;
			}
		}
	}
	person[2].score = cnt3;

	
	int M = max(max(person[0].score, person[1].score), person[2].score);
	cout << M << endl;
	for (int i = 0; i < 3; i++) {
		if (M == person[i].score) {
			cout << person[i].name << endl;
		}
	}
	
	return 0;
}


