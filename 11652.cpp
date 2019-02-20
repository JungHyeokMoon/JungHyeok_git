#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	map<long long, int >d; //첫번째수는 입력받은수, 두번째수는 입력받은 개수

	for (int i = 0; i < n; i++) {
		long long x;
		scanf("%lld", &x);
		d[x] += 1;
	}

	int m = 0;
	long long ans = 0;

	for (auto &p : d) {
		if (m < p.second) {
			m = p.second;
			ans = p.first;
		}//입력받은 개수가 많은걸로 초기화해줌
		else if (m == p.second && p.first < ans) {// 입력받은수가 같으면 작은수로 정답을초기화
			ans = p.first;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
