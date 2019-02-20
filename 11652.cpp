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

	map<long long, int >d; //ù��°���� �Է¹�����, �ι�°���� �Է¹��� ����

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
		}//�Է¹��� ������ �����ɷ� �ʱ�ȭ����
		else if (m == p.second && p.first < ans) {// �Է¹������� ������ �������� �������ʱ�ȭ
			ans = p.first;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
