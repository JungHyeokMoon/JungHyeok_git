#include <iostream>
#include <vector>
using namespace std;

int l, p;
int main() {
	cin >> l >> p;
	vector<int> v(5, 0);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < 5; i++) {
		cout << v[i] - (l*p) << " ";
	}
	cout << endl;

	return 0;
}