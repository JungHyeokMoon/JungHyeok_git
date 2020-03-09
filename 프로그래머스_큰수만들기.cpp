#include <string>
#include <vector>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string solution(string number, int k) {
    stack<char> stk;
    int length=number.size();
    string answer = "";
    int deletecount=0;
    bool flag=false;
    int lastIndex=0;
    for(int i=0; i<length ; i++){
        while(!stk.empty() && stk.top()<number[i]){
            stk.pop();
            deletecount++;
            lastIndex=i;
            if(deletecount==k){
                flag=true;   
                break;
            }
        }
        if(flag){
            break;
        }
        stk.push(number[i]);
    }
    int l=number.size()-k;
    if(!flag){
        while(stk.size()!=l){
            stk.pop();
        }
        while(!stk.empty()){
            answer+=stk.top();
            stk.pop();
        }
        reverse(answer.begin(),answer.end());
    }else{
        while(!stk.empty()){
            answer+=stk.top();
            stk.pop();
        }
        reverse(answer.begin(),answer.end());
        for(int i=lastIndex; i<length ; i++){
            answer+=number[i];
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
//mononestack 알고리즘으로