#include <string>
#include <vector>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    //n은 총학생수, lost 은 체육복을 도난당한 학생들의 번호, reserve는 여벌의체육복을 가져온 학생들
    int answer=n-lost.size();
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]==reserve[j]){
                lost[i]=-1;
                reserve[j]=-1;
                answer++;
                break;
            }
        }
    }
    //여벌의 체육복을 가져온 학생이 도난당했을경우 제외 -1처리
    
    for(int i=0; i<lost.size(); i++){
        if(lost[i]==-1){
            continue;
        }
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]==reserve[j]+1||lost[i]==reserve[j]-1){
                reserve[j]=-1;
                answer++;
                break;
            }
        }
    }
    
    return answer;
}