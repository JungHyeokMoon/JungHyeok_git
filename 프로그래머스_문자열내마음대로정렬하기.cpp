#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int N;
bool compare(const string &a, const string &b){
    char A=a[N];
    char B=b[N];
    if(A<B){
        return true;
    }else if(A==B){
        return a<b;
    }else{
        return false;
    }
}
vector<string> solution(vector<string> strings, int n) {
    N=n;
    sort(strings.begin(),strings.end(),compare);
    return strings;
}//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges