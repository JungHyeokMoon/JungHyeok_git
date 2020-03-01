#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; //bridage_length 다리길이 , weight 다리가 최대로 버틸수있는 무게, truck_weights들은 트럭들의무게
    int i=0;
    queue<int> q;
    int cnt=0;
    int trucks=truck_weights.size();
    while(1){
        answer++;
        if(q.size()==bridge_length){
            int temp=q.front();
            q.pop();
            if(temp){
                cnt++;
                weight+=temp;
            }
        }
        if(cnt==trucks){
            break;
        }
        if(weight>=truck_weights[i]){
            weight-=truck_weights[i];
            q.push(truck_weights[i++]);
        }
        else{
            q.push(0);
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges