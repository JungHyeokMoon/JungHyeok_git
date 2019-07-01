#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
int t, n; //t 학기수 n과목수 c학점 g성적
int sum;
double gpa;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n; //들은 과목의수
		int c;
		double g;
		for (int j = 0; j < n; j++) {
			
			cin >> c >> g;
			sum += c;
			gpa = gpa + g * c;
		}
		gpa = double(gpa / sum);
		gpa = round(gpa * 10) / 10;
		cout << sum << " " << gpa << endl;
		sum = 0;
		gpa = 0;
	}
	
	return 0;
}
