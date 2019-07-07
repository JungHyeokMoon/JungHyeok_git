#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
int sum = 0;
string s;
/*int solve(int num) {

	while (num != 0) {
		sum = sum + num % 10;
		num = num / 10;
	}
	return sum;
}*/
int ret;
int foo(string str) {
	int n = str.size();
	for (int i = 0; i < n; i++) {
		sum = sum + (str[i] - '0');
	}
	return sum;
}

int main() {

	while (1) {
		
		cin >> s;
		ret=foo(s);
		if (ret == 0) {
			return 0;
		}
		else {
			
			while (1) {
				if (ret < 10) {
					cout << ret << endl;
					sum = 0;
					break;
				}
				else {
					sum = 0;
					s = to_string(ret);
					ret = foo(s);
				}
			}
		}
		
		
	}
	return 0;
}
