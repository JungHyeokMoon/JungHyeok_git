#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <queue>
#include <cstring> //memset�Լ�
using namespace std;

vector<int> a[1000+1];
int check[1000 + 1];

void dfs(int x) {
	check[x] = true;
	//printf("%d ", x);
	for (unsigned int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false)
			dfs(y);
	}
}

void bfs(int x) {
	queue<int> q;
	memset(check, false, sizeof(check)); //dfs�� �ϰ� ���Ŀ� check �迭�� �޶��������Ƿ� �س����Ѵ�
	check[x] = true;
	q.push(x);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		printf("%d ", x);
		for (unsigned int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}
	}

}

int main() {
	int n, m;
	int component = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int to, end;
		scanf("%d %d", &to, &end);
		a[to].push_back(end);
		a[end].push_back(to);
	}

	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}//�̰� ������� ������ȣ�� 1�����̰� ��������� ��ȣ�������������� ���Ƿ�


	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			component += 1;
		}
		
	}//��������� ���� ������ �湮���� �ʾ����� dfs���ϰ� ����+1����, dfs�� bfs�� ��� ������ �ѹ��� Ž���ϱ⶧���̴�.

	printf("%d\n", component);
	return 0;

}

