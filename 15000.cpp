#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;

    int len=s.size();

    for(int i=0; i<len; ++i){
        s[i]=(char)(s[i]-'a'+'A');
    }

    cout<<s;

    return 0;
}