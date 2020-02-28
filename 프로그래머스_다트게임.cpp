#include <string>
#include <bits/stdc++.h>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int length=dartResult.size();
    queue<int> q;
    int result[3]={0};
    int resultindex=0;
    int bonus[3]={1,1,1};
    int temp=0;
    for(int i=0; i<length; i++){
        char letter=dartResult[i];
        if(0<=letter-'0'&&letter-'0'<=9){
            q.push(letter-'0');
        }
        else if(letter=='S'||letter=='D'||letter=='T'){
            while(!q.empty()){
                temp+=q.front()*pow(10,q.size()-1);
                q.pop();
            }
            if(letter=='S'){
                temp=pow(temp,1);
            }else if(letter=='D'){
                temp=pow(temp,2);
            }else{
                temp=pow(temp,3);
            }
            result[resultindex++]=temp;
            temp=0;
        }
        else if(letter=='*'){
            bonus[resultindex-1]*=2;
            if(resultindex-2>=0){
                bonus[resultindex-2]*=2;
            }
        }
        else{//'#'인경우
            bonus[resultindex-1]=-1;
        }
    }
    for(int i=0; i<3; i++){
        answer+=result[i]*bonus[i];
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges