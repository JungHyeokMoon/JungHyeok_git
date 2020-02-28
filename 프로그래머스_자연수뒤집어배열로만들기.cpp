#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while(n!=0){
        answer.push_back(n%10);
        n=n/10;
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges