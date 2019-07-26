	#include <iostream>
	#include <string>
	#include <vector>
	#include <queue>
	#include <algorithm>

	using namespace std;
	string rev(int num) {
		string s = "";
		while (num != 0) {
			int temp = num % 10;
			if (temp == 0) {
				if (s == "") {
					num /= 10;
					continue;
				}

			}
			s += temp + '0';
			num /= 10;
		}
		return s;
	}
	int x, y;
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		std::cout.tie(NULL);
	
		cin >> x >> y;
		int x1 = stoi(rev(x));
		int y1 = stoi(rev(y));
		//cout << x1 << " " << y1 << endl;
		cout << rev(x1 + y1) << endl;
		return 0;
	}


