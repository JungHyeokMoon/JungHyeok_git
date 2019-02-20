#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
using namespace std;


int cnt[10000 + 1];
int main() {
	int n;
	scanf("%d", &n);

	int temp = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		cnt[temp] += 1;
	}//cnt[i] 를 입력으로 들어온 수중에서 i가 몇개 있는지를 저장
	for (int i = 0; i <= 10000; i++) {
		if (cnt[i] > 0) {// 1~10000까지에 수중 입력받은개수가 1이상이면
			for (int j = 0; j < cnt[i]; j++) {
				printf("%d\n", i);// 입력받은수만큼 출력한다.
			}
		}
	}

	return 0;
}