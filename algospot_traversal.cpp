#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C, N;

vector<int> slice(vector<int>v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}
void printPostorder(vector<int> pre, vector<int> in) {
	int n = pre.size();
	if (pre.empty())return;

	int root = pre[0];
	int L = find(in.begin(), in.end(), root) - in.begin(); // 
	int R = n - L - 1;

	printPostorder(slice(pre, 1, L + 1), slice(in, 0, L));
	printPostorder(slice(pre, L + 1, n), slice(in, L + 1, n));

	cout << root << ' ';
	 

}
int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		vector<int> preorder, inorder;
		preorder = vector<int>(N);
		inorder = vector<int>(N);
		for (int i = 0; i < N; i++) {
			cin >> preorder[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> inorder[i];
		}
		printPostorder(preorder, inorder);
		cout << endl;
	}
	return 0;
}