#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int length=phone_book.size();
    for(int i=0; i<length ; i++){
        map<string,int> m;
        int i_length=phone_book[i].size();
        string temp="";
        temp+=phone_book[i][0];
        for(int j=1; j<i_length; j++){
            temp+=phone_book[i][j];
            m[temp]++;
        } //접두어를 맵에다 넣고
        
        for(int j=0; j<length ; j++){
            if(i==j){
                continue;
            }
            if(phone_book[j].size()==1){
                if(phone_book[i][0]==phone_book[j][0]){
                    return false;
                }
            }
            if(phone_book[j].size()==i_length){
                if(phone_book[i]==phone_book[j]){
                    return false;
                }
            }
            string temp2="";
            temp2+=phone_book[j][0];
            for(int k=1; k<phone_book[j].size(); k++){
                temp2+=phone_book[j][k];
                if(m.find(temp2)!=m.end()){
                    return false;
                }
            }
        }
    }
    return answer;
}
//실패한코드

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int length=phone_book.size();
    for(int i=0; i<length ; i++){
        for(int j=0; j<length ; j++){
            if(i==j)continue;
            if(phone_book[i].find(phone_book[j])==0)return false; //접두어니까 return 위치가 바로 0으로와야함
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges