#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
bool chess[8][8] = { {true,false,true,false,true,false,true,false},
				  {false,true,false,true,false,true,false,true},
				  {true,false,true,false,true,false,true,false},
				  {false,true,false,true,false,true,false,true},
				  {true,false,true,false,true,false,true,false},
				  {false,true,false,true,false,true,false,true},
				  {true,false,true,false,true,false,true,false},
				  {false,true,false,true,false,true,false,true},
};//true 흰 false검*/
char arr[9][9];
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 'F' && chess[i][j] == true) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	//체스판을직접만들지말고 (i+j)%2==0 이렇게하는방법도있다
	return 0;
}



