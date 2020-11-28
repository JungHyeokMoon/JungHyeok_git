#include <bits/stdc++.h>
using namespace std;
//십진수 n진수 변환 함수
string toNdigit(int hnum, int n, char * charToInt){
    string str;
    while(hnum/n>0){
        str=charToInt[hnum%n]+str;
        hnum=hnum/n;
    }
    str=charToInt[hnum%n]+str;
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    //모듈러 연산을 위해 p를 하나 줄여줘야한다.
    p--;
    int j=0;
    int hnum=0;
    int cnt=0;
    //모든숫자는 0부터시작
    string nHnum="0";
    char charToInt[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    for(int i=0; ; i++){
        //모듈러 연산 순차적으로 돌아야하니깐
        if(i%m==0)i=i%m;
        //자기 차례가오면 answer에 추가해주면된다.
        if(i==p){
            //추가
            answer+=nHnum[j];
            cnt++;
            //탈출조건
            if(cnt==t)break;
        } 
        //원형으로 계속 돌아야하니깐, 즉 nHum을 계속해서 순회해야함
        j++;
        //당장 출력할 숫자를 다 순회했다면
        if(j==nHnum.size()){
            //다시만들어야함
            hnum++;
            nHnum=toNdigit(hnum,n,charToInt);
            //인덱스도 다시 0으로
            j=0;
        }
        
    }
    return answer;
}

int main(){
    // cout<<solution(2,4,2,1)<<endl;
    // cout<<solution(16,16,2,1)<<endl;
    // cout<<solution(16,16,2,2)<<endl;

    return 0;
}