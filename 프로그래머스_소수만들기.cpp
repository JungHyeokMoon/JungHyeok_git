#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int length;
vector<int> numbers;
vector<bool> selected;
bool eratos[3001]={false};
int answer = 0;
void Sosu(){
    eratos[0]=true;
    eratos[1]=true;
    for(int i=2; i*i<=3000; i++){
        if(!eratos[i]){
            for(int j=2*i; j<=3000; j+=i){
                eratos[j]=true; //false들이 소수
            }
        }
    }
}
void Make_Three_Numbers(int idx,int cnt,vector<int> & nums){
    if(cnt==3){
        int temp=0;
        for(int i=0; i<3; i++){
            temp+=numbers[i];
        }
        if(!eratos[temp])answer++;
        // for(int i=0; i<3; i++){
        //     cout<<numbers[i]<<" ";
        // }
        // cout<<endl;
        return ;
    }
    for(int i=idx; i<length ; i++){
        if(selected[i])continue;
        selected[i]=true;
        numbers[cnt]=nums[i];
        Make_Three_Numbers(i,cnt+1,nums);
        selected[i]=false;
    }
}
int solution(vector<int> nums) {
    length=nums.size();
    numbers.resize(3);
    selected.resize(length,false);
    Sosu();
    
    Make_Three_Numbers(0,0,nums);


    return answer;
}