#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;

    int n=s.size();
    int ans=0;
    for(int i=0; i<n; i++){
       if('0'<=s[i]&&s[i]<='9')
            s[i]=s[i]-'0';
        else if('A'<=s[i]&&s[i]<='F')
            s[i]=(s[i]-'A'+10);
        else if('a'<=s[i]&&s[i]<='f')
            s[i]=(s[i]-'a'+10);

        ans=(ans*16)+s[i];
    }

    printf("%d\n", ans);

    return 0;
}