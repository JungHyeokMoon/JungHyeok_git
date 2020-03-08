#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> stk;
    int length=arrangement.size();
    for(int i=0; i<length ; i++){
        if(arrangement[i]=='('){
            stk.push(i);
        }
        else{
            if(i-stk.top()==1){
                stk.pop();
                answer+=stk.size();
            }
            else{
                stk.pop();
                answer+=1;
            }
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges