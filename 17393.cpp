#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <map>
#include <deque>
using namespace std;

int n;

vector <long long> ink;
vector<long long>viscosity;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	ink.resize(n);
	viscosity.resize(n);
	for (int i = 0; i < n; i++)
		cin >> ink[i];

	for (int i = 0; i < n; i++) {
		cin >> viscosity[i];
	}
	vector<long long>::iterator it;
	
	for (int i = 0; i < n; i++) {
		it = upper_bound(viscosity.begin(), viscosity.end(), ink[i]);
		int p = (int)(it-viscosity.begin());
		if (p < i + 1)cout << 0 << " ";
		else {
			cout << p-i-1 << " ";
		}
	}



	

	
	return 0;

}