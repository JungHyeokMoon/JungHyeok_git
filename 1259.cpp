#include <iostream>
using namespace std;

int main(){
    string s;
    int check=0;
    while(cin>>s){
        if(s.size()==1 &&(s[0]-'0')==0)
            break;
        int len=s.size();
        for(int i=0; i<len/2; ++i){
            if((s[i]-'0')!=(s[len-1-i]-'0')){
                check=1;
                break;
            }
        }
        if(check==0)
            printf("yes\n");
        else
            printf("no\n");
        check=0;
    }

    return 0;
}