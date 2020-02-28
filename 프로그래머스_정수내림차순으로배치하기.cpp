#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool compare(const int &a, const int &b){
    if(a>b){
        return true;
    }
    return false;
}
long long solution(long long n) {
    string temp=to_string(n);
    sort(temp.begin(),temp.end(),compare);
    long long answer = stoll(temp);
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges