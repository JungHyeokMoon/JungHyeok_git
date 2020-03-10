#include <iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int length=s.size();
    stack<char> stk;
    for(int i=0; i<length ; i++){
        if(stk.empty()){
            stk.push(s[i]);
        }
        else{
            if(s[i]==stk.top()){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
    }
    if(stk.empty()){
        return 1;
    }
    else{
        return 0;
    }

}