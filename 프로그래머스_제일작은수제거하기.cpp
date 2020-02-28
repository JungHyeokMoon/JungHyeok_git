#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> arr) {
    vector<int>::iterator it=min_element(arr.begin(),arr.end());
    it=arr.erase(it);
    if(arr.empty()){
        arr.push_back(-1);
    }
    
    return arr;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges