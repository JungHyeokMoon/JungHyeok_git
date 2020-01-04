#include <bits/stdc++.h>
using namespace std;

int n;
int alpha1[26];
int alpha2[26];

void init(){
    fill(alpha1,alpha1+26,0);
    fill(alpha2,alpha2+26,0);
    return ;
}

bool solve(string str1, string str2){
    int len1=str1.size();
    int len2=str2.size();

    if(len1!=len2){
        return false;
    }

    for(int j=0; j<len1; j++){
        alpha1[str1[j]-'a']++;
        alpha2[str2[j]-'a']++;
    }

    for(int i=0; i<26; i++){
        if(alpha1[i]!=alpha2[i]){
            return false;
        }
    }
    return true;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        init ();

        string str1,str2;
        cin>>str1>>str2;

        if(solve(str1,str2)){
            cout<<"Possible"<<"\n";
        }
        else{
            cout<<"Impossible"<<"\n";
        }
    }

    return 0;
}