#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int n;
bool arefriends[10][10] = { false };
bool taken[10] = { false };
int countparing(bool *taken) {
	//남은학생들 중 가장번호가 빠른애들 firstfree 중복을 막기위함이다
	int firstfree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstfree = i;
			break;
		}
	}
	//기저사례 모든학생이 짝을 찾았으면 한가지방법을 찾았으니 종료한다
	if (firstfree == -1)return 1;

	int ret = 0;
	for (int pairwith = firstfree + 1; pairwith < n; pairwith++) {
		if (!taken[pairwith] && arefriends[firstfree][pairwith]) {
			taken[firstfree]=taken[pairwith] = true;
			ret += countparing(taken);
			taken[firstfree]=taken[pairwith] = false; //여기가 중요 다른짝찾기위해 다시false해줘야함
		}
		
	}
	return ret;
}
int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int  m;
		scanf("%d %d",&n ,&m);
		 
		memset(taken, false, sizeof(taken));
		// 기본적인셋팅
		int i, j;
		for (int  k= 0; k < m; k++) {
			scanf("%d %d", &i, &j);
			arefriends[i][j] = true;
			arefriends[j][i] = true;
		}
		int answer = 0;
		answer=countparing(taken);
		printf("%d\n", answer);

		memset(arefriends, false, sizeof(arefriends));
		
	}
}
