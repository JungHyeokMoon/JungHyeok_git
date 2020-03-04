#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int length=people.size();
    sort(people.begin(),people.end());
    int answer = 0;
    int j=length-1;
    int i=0;
    while(i<=j){
        // cout<<people[i]<<", "<<people[j]<<endl;
        if(people[i]+people[j]<=limit){
            i++;
            j--;
            answer++;
        }
        else{
            j--;
            answer++;
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges