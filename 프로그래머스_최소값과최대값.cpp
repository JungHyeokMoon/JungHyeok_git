#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    int length=s.size();
    string temp="";
    int Max=-987654321;
    int Min=987654321;
    for(int i=0; i<length ; i++){
        if(i==length-1){
            temp+=s[i];
            int numtemp=stoi(temp);
            Max=max(Max,numtemp);
            Min=min(Min,numtemp);
        }
        else{
            if(s[i]==' '){
                int numtemp=stoi(temp);
                Max=max(Max,numtemp);
                Min=min(Min,numtemp);
                // cout<<"최소값 :"<<Min<<", 최대값 :"<<Max<<endl;
                temp.clear();
            }else{
                temp+=s[i];
            }
        }
    }
    string answer = "";
    answer+=to_string(Min);
    answer.push_back(' ');
    answer+=to_string(Max);
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges