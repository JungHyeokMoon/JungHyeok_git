#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;//각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.
    int work=progresses.size();
    int cnt=0;
    int h_idx=0;
    priority_queue<int,vector<int>,less<int>>pq;
    while(cnt!=work){
        int temp=0;
        for(int i=h_idx; i<work; i++){
            if(progresses[i]>=100) continue;
            progresses[i]+=speeds[i];
            if(progresses[i]>=100){
                if(i==h_idx){
                    temp++;
                    h_idx++;
                    while(!pq.empty()){
                        if(h_idx!=pq.top()){
                            break;
                        }else{
                            temp++;
                            h_idx++;
                        }
                    }
                }
                else{
                    pq.push(i);
                }
            }
        }
        if(temp){
            answer.push_back(temp);
            cnt+=temp;
        }
    }
    return answer;
}//시간초과코드

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;//각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.
    int h_idx=0;
    int work=progresses.size();
    queue<int> q;
    while(true){
        int temp=0;
        for(int i=0; i<work; i++){
            progresses[i]+=speeds[i];
        }
        if(progresses[h_idx]>=100){
            temp++;
            for(int i=h_idx+1; i<work; i++){
                if(progresses[i]<100){
                    h_idx=i;
                    break;
                }
                else{
                    temp++;
                    h_idx++;
                }
            }
            q.push(temp);
        }
        if(h_idx==work-1 && progresses[h_idx]>=100)break;
    }
    while(!q.empty()){
        answer.push_back(q.front());
        q.pop();
    }
    return answer;
}