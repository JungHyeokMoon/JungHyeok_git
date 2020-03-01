#include <string>
#include <vector>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int length=prices.size();
    for(int i=0; i<length; i++){
        int count=0;
        for(int j=i+1; j<length; j++){
            count++;
            if(prices[i]>prices[j]){
                break;
            }
        }
        answer.push_back(count);
    }   
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges