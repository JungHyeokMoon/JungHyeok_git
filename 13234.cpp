#include <iostream>
#include <string>
using namespace std;

int main(){
    string a,b;
    string tof;
    
    cin>>a>>tof>>b;

    int t,f;
    int check;
    if(a=="true" && b=="true"){
        t=2;
        f=0;
        check=1;
    }
    else if((a=="true"&&b=="false")||(a=="false"&&b=="true")){
        t=1;
        f=1;
        check=2;
    }
    else{
        t=0;
        f=2;
        check=3;
    }

    if(tof=="AND"){
        if(check==1)
            printf("true\n");
        else
            printf("false\n");
    }
    else if(tof=="OR"){
        if(check==3)
            printf("false\n");
        else
            printf("true\n");
        
    }

    return 0;
}



