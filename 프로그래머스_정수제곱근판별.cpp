#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long temp=sqrt(n);
    answer=(temp*temp==n) ? (temp+1)*(temp+1) : -1;
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges