#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int k;
vector<int> s;

vector<int>v;
/*void dfs(int depth,int num) {
	if (depth == 6) {
		for (int i = 0; i < depth; i++) {
			cout << v[i] << " ";
		}
		cout << endl;

		return;
	}

	
	
	for (int i = num; i < k; i++) {
		v.push_back(s[i]);
		dfs(depth + 1, i + 1);
		v.pop_back();
	}

}*/
void dfs(int num) {
	int n = v.size();
	if (n == 6) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;

		return;
	}



	for (int i = num; i < k; i++) {
		v.push_back(s[i]);
		dfs(i + 1);
		v.pop_back();
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	while (true) {
		cin >> k;
		if (k == 0) {
			break;
		}
		else {
			for (int i = 0; i < k; i++) {
				cin >> num;
				s.push_back(num);
			}
			dfs(0);
			s.clear();
			cout << endl;
			
			
		}
	}
	return 0;
	
}
