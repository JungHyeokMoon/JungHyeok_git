#include <string>
#include <vector>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool compare(const pair<double,int> &a, const pair<double,int> &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    else{
        return a.first>b.first;
    }
}
vector<int> solution(int N, vector<int> stages) {//stages 에는 1이상 n+1이하의 자연수가담겨있다.
    int people=stages.size(); //사람몇명인지
    vector<int> answer;
    vector<int> temp(N+2);
    for(int i=0; i<people; i++){
        temp[stages[i]]++;
    }
    vector<pair<double,int>> failure;
    for(int i=1; i<=N ; i++){
        double fail;
        if(!temp[i]){
            fail=0;
        }
        else{
            fail=double(temp[i])/people;
            people-=temp[i];
        }
        failure.push_back({fail,i});
    }
    sort(failure.begin(),failure.end(),compare);
    for(auto i : failure){
        answer.push_back(i.second);
    }
    
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges