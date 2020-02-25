#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool compare(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first>=b.first && a.second<=b.second){
        return true;
    }
    return false;
}
vector<int> solution(vector<int> answers) {
    int A[5]={1,2,3,4,5};
    int B[6]={2,1,2,3,2,5};
    int C[10]={3,3,1,1,2,2,4,4,5,5};
    int length=answers.size();
    vector<pair<int,int>> v;
    int A_count=0;
    int B_count=0;
    int C_count=0;
    for(int i=0; i<length; i++){
        if(answers[i]==A[i%5]){
            A_count++;
        }
        if(answers[i]==B[i%6]){
            B_count++;
        }
        if(answers[i]==C[i%10]){
            C_count++;
        }
    }
    v.push_back({A_count,1});
    v.push_back({B_count,2});
    v.push_back({C_count,3});
    sort(v.begin(),v.end(),compare);

    
    vector<int> answer;
    answer.push_back(v[0].second);
    if(v[0].first==v[1].first){
        answer.push_back(v[1].second);
        if(v[1].first==v[2].first){
            answer.push_back(v[2].second);
        }
    }
    return answer;
}