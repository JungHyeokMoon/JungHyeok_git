#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
char a[101];
int main(){
	vector<int> v(26, -1);
	scanf("%s", a);

	int n = strlen(a);

	for(int i=0; i<n; i++){
		int num = a[i] - 'a'; //º¤ÅÍÀÇÀÎµ¦½º
		if (v[num] == -1)
			v[num] = i;
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}

	printf("\n");

	return 0;

}