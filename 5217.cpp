#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		int num;
		scanf("%d", &num);
		printf("Pairs for %d:", num);
		for (int i = 1; i < num - i; i++) {
			printf(" %d %d", i, num - i);
			if (i + 1 < num - (i + 1))
				printf(",");
		}
		printf("\n");
	}

	return 0;
}
