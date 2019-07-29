#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int c, n;
const int MAX = 101;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> c;
	for (int i = 0; i < c; i++) {
		memset(visited, false, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		queue <pair<int, pair<int, int>>>q;
		q.push(make_pair(arr[0][0], (make_pair(0, 0))));
		
		bool ok = false;
		visited[0][0] = true;

		while (!q.empty()) {
			int weight = q.front().first;
			int hx = q.front().second.first;
			int hy = q.front().second.second;
			//visited[hx][hy] = true;
			q.	pop();
			if (hx==n-1 && hy==n-1) {
				cout << "YES" << endl;
				ok = true;
				break;
			}
			int nx1 = hx + weight;
			int ny1 = hy;
			if ((nx1 < n && ny1 < n) && visited[nx1][ny1] == false) {
				visited[nx1][ny1] = true;
				q.push(make_pair(arr[nx1][ny1], make_pair(nx1, ny1)));
			}
			int nx2 = hx;
			int ny2 = hy + weight;
			if ((nx2 < n && ny2 < n) && visited[nx2][ny2] == false) {
				visited[nx2][ny2] = true;
				q.push(make_pair(arr[nx2][ny2], make_pair(nx2, ny2)));
			}
		}

		if (!ok)cout << "NO" << endl;

	}
	return 0;
}



