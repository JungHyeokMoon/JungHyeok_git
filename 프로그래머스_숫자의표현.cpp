#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1; i<=n; i++){
        int temp=i;
        // cout<<"i:"<<i<<endl;
        int num=0;
        while(num<n){
            num+=temp++;
            // cout<<temp<<endl;
        }
        if(num==n){
            answer++;
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges