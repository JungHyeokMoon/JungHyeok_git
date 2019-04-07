#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int n;
bool arefriends[10][10] = { false };
bool taken[10] = { false };
int countparing(bool *taken) {
	//�����л��� �� �����ȣ�� �����ֵ� firstfree �ߺ��� ���������̴�
	int firstfree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstfree = i;
			break;
		}
	}
	//������� ����л��� ¦�� ã������ �Ѱ�������� ã������ �����Ѵ�
	if (firstfree == -1)return 1;

	int ret = 0;
	for (int pairwith = firstfree + 1; pairwith < n; pairwith++) {
		if (!taken[pairwith] && arefriends[firstfree][pairwith]) {
			taken[firstfree]=taken[pairwith] = true;
			ret += countparing(taken);
			taken[firstfree]=taken[pairwith] = false; //���Ⱑ �߿� �ٸ�¦ã������ �ٽ�false�������
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
		// �⺻���μ���
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
