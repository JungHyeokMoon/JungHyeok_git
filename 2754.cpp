#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;

    if(s=="A+"){
        printf("4.3\n");
    }
    else if(s=="A0")
        printf("4.0\n");
    else if(s=="A-")
        printf("3.7\n");
    else if(s=="B+")
        printf("3.3\n");
    else if(s=="B0")
        printf("3.0\n");
    else if(s=="B-")
        printf("2.7\n");
    else if(s=="C+")
        printf("2.3\n");
    else if(s=="C0")
        printf("2.0\n");
    else if(s=="C-")
        printf("1.7\n");
    else if(s=="D+")
        printf("1.3\n");
    else if(s=="D0")
        printf("1.0\n");
    else if(s=="D-")
        printf("0.7\n");
    else
        printf("0.0\n");


    return 0;
}