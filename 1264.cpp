#include <iostream>
#include <string>
using namespace std;

int main(){
    char vowel[]={'a','i','e','o','u','A','I','E','O','U'};
    string s;
    
    while(getline(cin,s)){
        if(s.size()==1 &&char(s[0])=='#'){
            break;
        }
        int ans=0;
        int len=s.size();
        for(int i=0; i<len; ++i){
            for(int j=0; j<10; ++j){
                if(s[i]==vowel[j])
                    ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;    
}