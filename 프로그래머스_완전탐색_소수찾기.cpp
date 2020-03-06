#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<bool> eratos;
int length=0;

string temp;
void sosu(int number){
    eratos.resize(number+1,false);
    eratos[0]=true;
    eratos[1]=true;
    for(int i=2 ; i*i<=number; i++){
        if(!eratos[i]){
            for(int j=2*i; j<=number; j+=i){
                eratos[j]=true;//false인것들이 소수
            }
        }
    }
}
bool compare(const int &a, const int &b){
    return a>b;
}

int solution(string numbers) {
    int answer = 0;
    length =numbers.size();
    sort(numbers.begin(),numbers.end(),compare);
    sosu(stoi(numbers));

    
    string s=numbers;
    sort(s.begin(), s.end());
    
    set<int> check;
    string temp;
    do{
        for(int i=1; i<=length; i++){
            temp=s.substr(0,i);
            int temp_num=stoi(temp);
            cout<<temp_num<<endl;
            if(!eratos[temp_num]){
                check.insert(temp_num);
            }
        }
    }while(next_permutation(s.begin(),s.end()));
    //numbers는 길이가 1이상 7 이하인 문자열
    //1부터 length 까지 나올수 있는 숫자문자열을 구해서 겹치는것없이
    //length 가 3이라하면 한자리 두자리 세자리 나올수 있는 문자열을 다구해서 
    //중복 제거 011 같이 앞에 0 제거 해서 소수체크  stoi와 set을 통해 제거했다.
    
    return answer=check.size();
}
