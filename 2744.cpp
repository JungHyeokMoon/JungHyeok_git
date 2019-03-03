#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;

    int len=s.size();
    for(int i=0; i<len; i++){
        if('A'<=s[i]&&s[i]<='Z')
            cout<<(char)(s[i]-'A'+'a');
        else if('a'<=s[i]&&s[i]<='z')
            cout<<(char)(s[i]-'a'+'A');
    }
    printf("\n");
}