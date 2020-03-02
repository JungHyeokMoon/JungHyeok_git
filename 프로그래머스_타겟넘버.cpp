#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> numbers, int target) {
    int length=numbers.size();
    int answer=0;
    queue<int> q;
    q.push(numbers[0]);
    q.push(-numbers[0]);
    
    for(int i=1; i<length; i++){
        int qSize=q.size();
        for(int j=0; j<qSize; j++){
            q.push(q.front()+numbers[i]);
            q.push(q.front()-numbers[i]);
            q.pop();
        }
    }
    while(!q.empty()){
        int front=q.front();
        q.pop();
        if(front==target){
            answer++;
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges