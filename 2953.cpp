#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int arr[5][4];
int sum[5];

priority_queue < pair<int, int>, vector < pair<int, int>>> pq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
			sum[i] += arr[i][j];
		}
		pq.push(make_pair(sum[i], i+1));
	}
	cout << pq.top().second << " " << pq.top().first << endl;
	return 0;
}
