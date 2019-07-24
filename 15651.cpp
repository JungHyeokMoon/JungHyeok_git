#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> arr;
const int MAX = 9;
bool visited[MAX];

void p(int idx ,int depth) {
	if (depth == m) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout <<'\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		//if (visited[i] == true)continue;
		arr.push_back(i);
		visited[i] = true;

		p(idx+1,depth + 1);

		arr.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n >> m;
	p(1,0);
}