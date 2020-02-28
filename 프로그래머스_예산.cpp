#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(),d.end());
    int answer = 0;
    int length=d.size();
    int money=0;
    for(int i=0; i<length ; i++){
        if(money+d[i]<=budget){
            money+=d[i];
            answer++;
        }
        else{
            break;
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges