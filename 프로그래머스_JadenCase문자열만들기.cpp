#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int length=s.size();
    string temp;
    for(int i=0; i<length; i++){
        if(s[i]==' '){
            answer+=temp;
            answer.push_back(' ');
            temp.clear();
        }else{
            if(temp.empty()){
                if('a'<=s[i]&&s[i]<='z'){
                    temp.push_back((s[i]-'a')+'A');
                }else{
                    temp.push_back(s[i]);
                }
            }
            else{
                if('A'<=s[i]&&s[i]<='Z'){
                    temp.push_back((s[i]-'A')+'a');
                }else{
                    temp.push_back(s[i]);
                }
            }
        }
    }
    answer+=temp;
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges