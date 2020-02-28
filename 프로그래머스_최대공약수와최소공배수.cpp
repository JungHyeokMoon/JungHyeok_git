#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int Get_gcd(int n,int m){
    if(m==0){
        return n;
    }
    else{
        return Get_gcd(m,n%m);
    }
}
vector<int> solution(int n, int m) {
    int gcd=Get_gcd(n,m);
    int lcm=n*m/gcd;
    vector<int> answer;
    answer.push_back(gcd);
    answer.push_back(lcm);
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges