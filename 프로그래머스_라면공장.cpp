#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int>> pq;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int time=0;
    int idx=0; 
    int lastIndex=supplies.size()-1;
    while(time!=k){
        if(dates[idx]==time){
            pq.push(supplies[idx]);
            if(idx!=lastIndex){
                idx++;
            }
        }
        if(stock==0){
                stock+=pq.top();
                pq.pop();
                answer++;
            }
        stock--; //밀가루1톤소모
        time++;
    }
    return answer;
}