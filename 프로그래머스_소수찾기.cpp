#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int Eratos(bool * arr,int n){
    memset(arr,false,sizeof(arr));
    for(int i=2; i*i<=n; i++){
        if(!arr[i]){
            for(int j=2*i; j<=n; j=j+i){
                arr[j]=true;
            }
        }
    }
    int cnt=0;
    for(int i=2; i<=n; i++){
        if(!arr[i])cnt++;
    }
    return cnt;
}
int solution(int n) {
    bool arr[1000001];
    int answer = Eratos(arr,n);
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges