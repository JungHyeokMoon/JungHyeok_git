#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
string tolower(string input, int stringsize){
    string ret="";
    for(int i=0; i<stringsize; i++){
        // ret+=(input[i]-'a')+'A';
        if('a'<=input[i] && input[i]<='z'){
            ret+=input[i];
        }
        else{
            ret+=(input[i]-'A')+'a';
        }
    }
    return ret;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int length=cities.size();
    
    if(cacheSize==0){
        answer=5*length;
        return answer;
    }
    vector<string> cache;
    vector<string>::iterator it;
    for(int i=0; i<length; i++){
        string compstring=tolower(cities[i],cities[i].size());
        bool flag=false;
        for(it=cache.begin(); it!=cache.end(); it++){
            if(*it==compstring){
                answer++;
                flag=true;
                cache.erase(it++);
                cache.push_back(compstring);
                break;
            }//hit
        }
        if(flag){
            continue;
        }
        //못찾았을경우
        answer+=5;
        if(cache.size()>=cacheSize){
            cache.erase(cache.begin());
            cache.push_back(compstring);
        }//가득찬경우
        else{
            cache.push_back(compstring);
        }
    }

    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges