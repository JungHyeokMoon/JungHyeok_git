#include <bits/stdc++.h>
using namespace std;
vector<int> make_failure(string & p){
    int p_length=p.size();
    vector<int> failure(p_length,0);
    int j=0;
    for(int i=1; i<p_length; i++){
        while(j>0 && p[i]!=p[j])j=failure[j-1];
        if(p[i]==p[j])failure[i]=++j;
    }
    return failure;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t,p;
    getline(cin,t);
    getline(cin,p);
    int t_length=t.size();
    int p_length=p.size();
    vector<int> failure=make_failure(p);
    vector<int> answer;
    
    int j=0;
    for(int i=0; i<t_length; i++){
        while(j>0 && t[i]!=p[j])j=failure[j-1];
        if(t[i]==p[j])j++;
        if(j==p_length){
            answer.push_back(i-p_length+2);
            j=failure[j-1];
        }
    }
    cout<<answer.size()<<endl;
    for(auto num :answer)
        cout<<num<<" ";
    return 0;
}