
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
string int_to_two(int num,int length){
    string temp="";
    while(num!=0){
        temp.push_back((num%2)+'0');
        num=num/2;
    }
    reverse(temp.begin(),temp.end());
    while(temp.size()!=length){
        temp.insert(temp.begin(),'0');
    }
    return temp;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<n; i++){
        string temp1=int_to_two(arr1[i],n);
        string temp2=int_to_two(arr2[i],n);
        string temp3="";
        for(int j=0; j<n; j++){
            if(temp1[j]=='1'||temp2[j]=='1'){
                temp3.push_back('#');
            }else if(temp1[j]=='0' && temp2[j]=='0'){
                temp3.push_back(' ');
            }
        }
        answer.push_back(temp3);
    }

    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges