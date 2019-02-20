#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> a(n);//n개의 공간을만들고

	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].second, &a[i].first); 

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
		printf("%d %d\n", a[i].second, a[i].first);

	return 0;
}

//문제풀때 y좌표가 증가하는순으로 정렬을 하라고했다. sort를 간편하게 활용하기위해서 바꿔서 입출력을했음
