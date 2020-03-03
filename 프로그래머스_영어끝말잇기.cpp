#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<string,int>m;
vector<int> solution(int n, vector<string> words) {
    int length=words.size();
    vector<int> people(n,0);
    m[words[0]]++;
    people[0]++;
    map<string,int>::iterator it;
    vector<int> answer;
    string previous=words[0];
    for(int i=1; i<length; i++){
        
        people[i%n]++; //몇번째사람이 몇번말한건지
        string temp=words[i];
        it=m.find(temp);
        if(it!=m.end()||previous.back()!=temp[0]){
            //TO DO: 몇번째사람인지 자신의몇번째에서 얘기를했는지
            answer.push_back(i%n+1);
            answer.push_back(people[i%n]);
            break;
        }//이미있다는이야기 그럼 탈락 
        previous=words[i];//이전단어 업데이트
        m.insert({temp,1});
        
    }
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges