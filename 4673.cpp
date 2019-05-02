#include <iostream>
using namespace std;
#define N 10001
bool arr[N]; //배열저장

int main() {
	int sum = 0;
	int n = 0;
	for (int i = 1; i < N; i++) {
		n = i;
		sum = n;//숫자그자체
		while (n != 0) {
			sum += (n % 10);
			n = n/10;
		} // 자릿수더해보고
		
		if (sum <= N)
			arr[sum] = true;

	}

	for (int i = 1; i < N; i++) {
		if (arr[i] == false)
			printf("%d\n", i);
	}

	return 0;
}