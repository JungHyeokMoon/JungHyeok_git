#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int length=clothes.size();
    map<string,int> m;
    for(int i=0; i<length; i++){
        string kind=clothes[i][1];
        m[kind]++;
    }
    for(auto i:m){
        answer*=(i.second+1);
    }
    
    answer-=1;
    
    return answer;
}