#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int length=skill_trees.size();
    map<char,int> m;
    for(int i=0; i<skill.size(); i++){
        m[skill[i]]++;
    }
    
    for(int i=0; i<length ; i++){
        int k=0;
        bool flag=false;
        for(int j=0; j<skill_trees[i].size(); j++){
            if(m.find(skill_trees[i][j])==m.end()){
                
            }//그냥괜찮다
            else{
                if(skill[k]==skill_trees[i][j]){
                    k++;
                }
                else{
                    //순서가안맞는경우
                    flag=true;
                    break;
                }
            }
        }
        if(!flag){
           answer++; 
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges