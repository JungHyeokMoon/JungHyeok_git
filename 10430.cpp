#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);
	
	printf("%d\n",(A+B)%C );
	printf("%d\n", (A + B) % C);
	printf("%d\n", (A*B) % C);
	printf("%d\n", (A*B) % C);

	return 0;
}