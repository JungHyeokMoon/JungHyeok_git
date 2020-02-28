#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int length1=arr1.size();
    int length2=arr1[0].size();
    answer.resize(length1);
    for(int i=0; i<length1; i++){
        for(int j=0; j<length2; j++){
            int temp=arr1[i][j]+arr2[i][j];
            answer[i].push_back(temp);
        }
    }
    
    
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges