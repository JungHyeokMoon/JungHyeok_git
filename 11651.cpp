#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> a(n);//n���� �����������

	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].second, &a[i].first); 

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
		printf("%d %d\n", a[i].second, a[i].first);

	return 0;
}

//����Ǯ�� y��ǥ�� �����ϴ¼����� ������ �϶���ߴ�. sort�� �����ϰ� Ȱ���ϱ����ؼ� �ٲ㼭 �����������
