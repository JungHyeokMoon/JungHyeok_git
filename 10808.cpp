#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
char a[101];
int main(){
	vector<int> v(26, 0);
	scanf("%s", a);

	int n = strlen(a);
	for (int i = 0; i < n; i++) {
		int num = a[i] - 'a';
		v[num]++;
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}

	printf("\n");

	return 0;

}