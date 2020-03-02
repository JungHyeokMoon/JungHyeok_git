#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int length =scoville.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0; i<length ; i++){
        pq.push(scoville[i]);
    }
    // cout<<pq.top();
    // int i=0;
    
    while((pq.top()<K) && pq.size()>1){
        answer++;
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        int input=first+second*2;
        // cout<<++i<<" 번째 :"<<first<<" , "<<second<<" , "<<input<<endl;
        pq.push(input);
    }
    if(pq.top()<K){
        return -1;
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges