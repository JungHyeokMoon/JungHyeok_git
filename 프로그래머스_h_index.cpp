#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//h번이상 인용된 논문이 h편이상이고 나머지 논문이 h번 이하 인용되었다면 h가 h_index
bool compare(const int &a , const int &b){
    return a>b;
}
int solution(vector<int> citations) {
    int answer = 0;
    int length=citations.size();
    sort(citations.begin(),citations.end(),compare);
    int Min=citations.back();
    if(Min>=length){
        return length;
    }
    for(int i=0; i<length ; i++){
        if(citations[i]<=i){
            answer=i;
            break;
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges