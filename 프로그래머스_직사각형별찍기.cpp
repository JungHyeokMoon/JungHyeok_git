#include <iostream>
#define endl "\n"
using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    for(int i=0; i<b; i++){
        for(int j=0;j<a;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    // cout << a + b << endl;
    return 0;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges