#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v;
string arr[5];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	for (int i= 0; i < 5; i++) {
		cin >> arr[i];
		v.push_back(arr[i].size());
	} //입력
	sort(v.begin(),v.end());
	for (int i = 0; i<v.back(); i++) {
		for (int j = 0; j < 5; j++) {
			if (i >= arr[j].size())continue;
			cout << arr[j][i];
		}
	}
	
	return 0;
}


