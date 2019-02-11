#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	string s1 = to_string(A) + to_string(B);//a와b를 스트링으로 만든후 더해줌 10 20 이면 1020으로
	string s2 = to_string(C) + to_string(D);
	
	long long n1 = stoll(s1); //문제의 숫자제한때문이다.
	long long n2 = stoll(s2);

	cout << n1 + n2 << endl;
	

	return 0;
	
}