
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string solution(string s, int n) {
    int length=s.size();
    for(int i=0; i<length ; i++){
        if(s[i]!=' '){
            char temp=('A'<=s[i] &&s[i]<='Z') ? 'A' : 'a';
            s[i]=temp+(s[i]-temp+n)%26;
        }
    }
    return s;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges