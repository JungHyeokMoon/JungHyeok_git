#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> arr;

void p(int idx, int depth) {
	if (depth == m) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout <<'\n';
		return;
	}

	for (int i = idx; i <n; i++) {
		
		arr.push_back(i+1);
		

		p(i+1,depth + 1);

		arr.pop_back();
		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n >> m;
	p(0,0);
}
