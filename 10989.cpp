// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <vector>
// #include <tuple>
// using namespace std;


// int cnt[10000 + 1];
// int main() {
// 	int n;
// 	scanf("%d", &n);

// 	int temp = 0;
// 	for (int i = 0; i < n; i++) {
// 		scanf("%d", &temp);
// 		cnt[temp] += 1;
// 	}//cnt[i] �� �Է����� ���� ���߿��� i�� � �ִ����� ����
// 	for (int i = 0; i <= 10000; i++) {
// 		if (cnt[i] > 0) {// 1~10000������ ���� �Է¹��������� 1�̻��̸�
// 			for (int j = 0; j < cnt[i]; j++) {
// 				printf("%d\n", i);// �Է¹�������ŭ ����Ѵ�.
// 			}
// 		}
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<int> A;
int n;
void Init(){
	cin>>n;
	A.resize(10001,0);
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		A[a]++;
	}
}
void Output(){
	for(int i=0; i<=10000; i++){
		if(A[i]!=0){
			int length=A[i];
			for(int j=0; j<length ; j++)
				cout<<i<<" ";
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	Init();
	Output();
	return 0;
}
