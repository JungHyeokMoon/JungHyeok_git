#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(string s)
{
    int length = s.size();
    string answer = "";
    int idx = length / 2;
    if (length % 2 == 0)
    {
        answer += s[idx - 1];
        answer += s[idx];
    } //짝수
    else
    {
        answer += s[idx];
    }

    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges