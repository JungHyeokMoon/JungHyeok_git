#include <bits/stdc++.h>
using namespace std;

int solution(int N, int number) {
    if(N==number)return 1;
    vector<set<int>> setV(8);
    int digit=N;
    for(int i=0; i<8; i++){
        setV[i].insert(digit);
        digit=digit*10+N;
    }
    
    for(int i=1; i<8; i++){
        for(int j=0; j<i; j++){
            for(auto & x : setV[j]){
                for(auto & y: setV[i-j-1]){
                    setV[i].insert(x+y);
                    setV[i].insert(x-y);
                    setV[i].insert(x*y);
                    if(y!=0)setV[i].insert(x/y);
                }
            }
        }
        if(setV[i].find(number)!=setV[i].end())return i+1;
    }
    return -1;
}

int main(){
    cout<<solution(5,12)<<endl;

    return 0;
}