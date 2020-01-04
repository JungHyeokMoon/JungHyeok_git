#include <bits/stdc++.h>
using namespace std;

int alpha1[26];
int alpha2[26];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    string A,B;
    cin>>A>>B;

    int len1=A.size();
    int len2=B.size();

    for(int i=0; i<len1; i++){
        alpha1[A[i]-'a']++;
    }
    for(int i=0; i<len2 ;i++){
        alpha2[B[i]-'a']++;
    }

    int cnt=0;

    for(int i=0; i<26; i++){
        if(alpha1[i]!=alpha2[i]){
            cnt+=abs(alpha1[i]-alpha2[i]);
        }
    }

    cout<<cnt<<"\n";
    return 0;
}