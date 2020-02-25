#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> solution(vector<int> answers) {
    int A[5]={1,2,3,4,5};
    int B[8]={2,1,2,3,2,4,2,5};
    int C[10]={3,3,1,1,2,2,4,4,5,5};
    int length=answers.size();
    int A_count=0;
    int B_count=0;
    int C_count=0;
    for(int i=0; i<length; i++){
        if(answers[i]==A[i%5]){
            A_count++;
        }
        if(answers[i]==B[i%8]){
            B_count++;
        }
        if(answers[i]==C[i%10]){
            C_count++;
        }
    }
    vector<int> answer;
    int max_val=max(C_count,max(A_count,B_count));
    if(max_val==A_count){
        answer.push_back(1);
    }
    if(max_val==B_count){
        answer.push_back(2);
    }
    if(max_val==C_count){
        answer.push_back(3);
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges