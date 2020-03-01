#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int I=arr1.size();
    int K=arr1[0].size();
    int J=arr2[0].size();
    
    vector<vector<int>> answer;
    answer.resize(I);
    for(int i=0; i<I; i++){
        answer[i].resize(J);
    }
    
    for(int i=0; i<I; i++){
        for(int j=0; j<J; j++){
            for(int k=0; k<K; k++){
                answer[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges