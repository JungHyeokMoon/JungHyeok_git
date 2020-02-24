#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#define endl "\n"
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string,int> M;
    int length=participant.size();
    for(int i=0 ;i<length; i++){
        M[participant[i]]++;
    }
    length=completion.size();
    for(int i=0; i<length; i++){
        M[completion[i]]--;
    }
    for(auto i:M){
        if(i.second!=0){
            string answer = i.first;
            
            return answer;
        }
    }
    
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges