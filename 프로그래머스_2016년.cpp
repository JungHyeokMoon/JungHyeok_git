#include <string>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

string solution(int a, int b) {
    string day[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int month[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int yoyil=0;
    for(int i=0; i<a-1; i++){
        yoyil+=month[i];
    }
    yoyil+=b;
    yoyil-=1;
    yoyil=yoyil%7;
    string answer = day[yoyil];
    return answer;
    
}