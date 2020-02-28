#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i=0; i<n; i++){
        answer.push_back(x+(x*i));
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges