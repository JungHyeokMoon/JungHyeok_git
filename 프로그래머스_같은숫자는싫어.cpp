#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int length=arr.size();
    int temp=arr[0];
    answer.push_back(temp);
    for(int i=1; i<length; i++){
        if(temp!=arr[i]){
            answer.push_back(arr[i]);
        }
        temp=arr[i];
        
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges