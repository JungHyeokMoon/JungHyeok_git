#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int length=phone_number.size();
    for(int i=length-5; i>=0; i--){
        phone_number[i]='*';
    }
    return phone_number;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges