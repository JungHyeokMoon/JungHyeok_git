#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(true){
        getline(cin, s);
        if(s=="") //이거없으면 출력초과뜬다 공백제한을두는것
            break;
        cout<<s<<endl;
    }

    return 0;
}