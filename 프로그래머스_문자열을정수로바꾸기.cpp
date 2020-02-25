#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int buho=1;
int temp_calc(){
    int temp=0;
    while(!q.empty()){
        temp+=q.front()*pow(10,q.size()-1);
        q.pop();
    }
    temp=temp*buho;
    return temp;
}
int solution(string s) {
    int length=s.size();
    int answer = 0;
    
    bool flag=false;
    for(int i=0; i<length ; i++){
        if(s[i]=='+'||s[i]=='-'){
            if(s[i]=='+'){
                buho=1;
            }
            else{
                buho=-1;
            }
            if(!flag){
                flag=true;
            }
            else{
                answer+=temp_calc();
            }
        }
        else{
            q.push(s[i]-'0');
        }

    }
    answer+=temp_calc();

    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges