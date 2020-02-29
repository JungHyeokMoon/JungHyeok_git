#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int length =priorities.size();
    
    queue<pair<int,int>>q; //우선순위, 인덱스 
    for(int i=0; i<length ;i++){
        q.push({priorities[i],i});
    }
    sort(priorities.begin(),priorities.end());
    int priorityidx=length-1;
    int prioritiyvalue=priorities[priorityidx];
    while(!q.empty()){
        int h_priority=q.front().first;
        int h_idx=q.front().second;
        if(h_priority==prioritiyvalue){
            q.pop();//출력
            answer++;
            if(h_idx==location){
                return answer;
            }
            priorityidx-=1;
            prioritiyvalue=priorities[priorityidx];
        }else{
            q.push({h_priority,h_idx});
            q.pop();
        }
    }
    
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges