#include <string>
#include <vector>

using namespace std;
int Solve(long long num){
    long long temp=num;
    for(int i=0; i<500; i++){
        if(temp==1){
            return i;
        }
        else if(temp%2==0){
            temp=temp/2;
        }
        else{
            temp=temp*3+1;
        }
    }
    return -1;
}
int solution(int num) {
    int answer = Solve(num);
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges