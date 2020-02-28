#include <string>
#include <vector>

using namespace std;
int Get_digit(int num){
    int ret=0;
    while(num!=0){
        ret+=num%10;
        num/=10;
    }
    return ret;
}
bool solution(int x) {
    bool answer;
    return answer=(x%Get_digit(x)==0) ? true : false;
    
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges