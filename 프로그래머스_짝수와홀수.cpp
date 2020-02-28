#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if(num==0){
        answer="Even";
        return answer;
    }
    else if(num%2==0){
        answer="Even";
    }
    else {
        answer="Odd";
    }
    
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges