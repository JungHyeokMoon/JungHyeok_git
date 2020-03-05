#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> order;
// vector<bool> isvisited;
int length;
int answer = -987654321;
vector<vector<int>> c_land;
void Solve(){
    int temp=0;
    for(int i=0; i<length; i++){
        temp+=c_land[i][order[i]];
    }
    answer=max(answer,temp);
}
void MakeOrder(int cnt){
    if(cnt==length){
        Solve();
        return ;
    }
    for(int i=0; i<4; i++){
        if(cnt!=0){
            if(order[cnt-1]==i)continue;
        }
        order[cnt]=i;
        MakeOrder(cnt+1);
    }
}
int solution(vector<vector<int> > land) //열의갯수는 4개
{
    
    length =land.size();
    order.resize(length,-1);
    c_land=land;
    MakeOrder(0);
    
    
    return answer;
}
//브루트포스로 풀었을경우 입력의 land의 사이즈가 십만이므로 시간초과가나온다.

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dp[100001][4];
int length;

int solution(vector<vector<int> > land) //열의갯수는 4개
{
    int answer=0;
    length =land.size();
    for(int i=0; i<4; i++){
        dp[0][i]=land[0][i];
    }
    for(int i=1; i<length ; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                if(j==k)continue;
                dp[i][j]=max(dp[i][j],land[i][j]+dp[i-1][k]);
            }
        }
    }
    for(int i=0; i<4; i++){
        answer=max(answer,dp[length-1][i]);
    }
    return answer;
}
//dp
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges