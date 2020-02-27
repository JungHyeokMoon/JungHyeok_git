#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int length=arr.size();
    for(int i=0; i<length ;i++){
        if(!(arr[i]%divisor)){
            answer.push_back(arr[i]);
        }
    }
    if(answer.size()==0){
        answer.push_back(-1);
    }else{
        sort(answer.begin(),answer.end());
    }
    
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges