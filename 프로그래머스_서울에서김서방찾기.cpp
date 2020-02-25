#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> seoul) {
    int length=seoul.size();
    string answer ="";
    for(int i=0; i<length; i++){
        if(seoul[i]=="Kim"){
            answer+="김서방은 "+to_string(i)+"에 있다";
            return answer;
        }
    }
    
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges