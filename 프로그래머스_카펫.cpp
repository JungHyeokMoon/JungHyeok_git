#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int sum=brown+red;
    int height=3;
    while(1){
        
        if(sum%height==0){
            int width=sum/height;
            for(int i=1; i<=width-2; i++){
                if((height-2)*i==red){
                    if((i+2)*height-red==brown){
                        answer.push_back(width);
                        answer.push_back(height);
                        return answer;
                    }
                }
            }
        }
        height++;
    }
    
    
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges