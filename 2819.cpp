#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;
int n,m;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
vector<int> survey_X;
vector<int> survey_Y;
string dir;

pair<int,int> hc={0,0};
long long disTance=0;
void Input(){
    cin>>n>>m;
    survey_X.resize(n);
    survey_Y.resize(n);
    for(int i=0; i<n; i++){
        cin>>survey_X[i]>>survey_Y[i];
        disTance=disTance+abs(survey_X[i])+abs(survey_Y[i]);
    }
    dir.resize(m);
    cin>>dir;
}
void GoDir(char c){
    if(c=='S'){
        hc.second+=1;
    }else if(c=='J'){
        hc.second-=1;
    }else if(c=='I'){
        hc.first+=1;
    }else{
        hc.first-=1;
    }
}
void distanceCal(int idx, char c){
    vector<int>::iterator it;
    int num;
    // cout<<"idx : "<<idx<<" ";
    if(c=='S'){
        it=upper_bound(survey_Y.begin(),survey_Y.end(),hc.second-1);
        num=(it-survey_Y.begin());
        disTance+=1*num;
        disTance-=1*(n-num);    
    }else if(c=='J'){
        it=lower_bound(survey_Y.begin(),survey_Y.end(),hc.second+1);
        num=(it-survey_Y.begin());
        disTance+=1*(n-num);
        disTance-=1*num;
    }
    else if(c=='I'){
        it=upper_bound(survey_X.begin(),survey_X.end(),hc.first-1);
        num=(it-survey_X.begin());
        disTance+=1*num;
        disTance-=1*(n-num);
    }
    else {
        it=lower_bound(survey_X.begin(),survey_X.end(),hc.first+1);
        num=(it-survey_X.begin());
        disTance+=1*(n-num);
        disTance-=1*num;
    }
    // cout<<"num : "<<num<<endl;
    
}
void Solve(){
    sort(survey_X.begin(),survey_X.end());
    sort(survey_Y.begin(),survey_Y.end());
    for(int i=0; i<dir.size(); i++){
        GoDir(dir[i]);
        distanceCal(i,dir[i]);
        cout<<disTance<<endl;
    }
}

int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Input();
    Solve();
    // vector<int> arr;
    // for(int i=0; i<5; i++){
    //     arr.push_back(i*10);
    // }
    // vector<int>::iterator it=lower_bound(arr.begin(),arr.end(),10);
    // cout<<(it-arr.begin())<<endl;
    return 0;
}