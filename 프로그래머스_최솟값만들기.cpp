#include <iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
bool compare(const int &a, const int &b){
    return a<b;
}
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),compare);
    int length=A.size();
    for(int i=0; i<length ; i++){
        answer+=A[i]*B[length-1-i];
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges