#include <bits/stdc++.h>
using namespace std;
bool Check(string &p ){
    stack<char> stk;
    for(auto ch : p){
        if(ch=='(')
            stk.push(ch);
        else {
            if(stk.empty())
                return false;
            else
                stk.pop();
        }
    }
    if(stk.empty())
        return true;
    return false;
}
string CustomerSubstr(string p){
    string temp;
    int length=p.size();
    for(int i=1; i<length-1;i++){
        if(p[i]=='(')
            temp.push_back(')');
        else
            temp.push_back('(');
    }
    return temp;
}
string Recursive(string p){
    
    if(p.empty())
        return "";
    string u;
    string v;
    
    int length=p.size();
    int left=0, right=0,idx=0;

    for(idx=0; idx<length ; ++idx){
        if(p[idx]=='(')
            left++;
        else
            right++;
        
        if(left==right)
            break;
    }
    
    u=p.substr(0,idx+1);
    v=p.substr(idx+1);
    if(Check(u))
        return u+Recursive(v);
    else{
        string temp="(";
        temp+=Recursive(v);
        temp+=')';
        temp+=CustomerSubstr(u);
        return temp;
    }
}
string solution(string p) {
    
    if(p.empty())
        return "";
    else if(Check(p))
        return p;
    return Recursive(p);
}

int main(){
    cout<<solution("(()())()")<<endl;;
    cout<<solution(")(")<<endl;
    cout<<solution("()))((()")<<endl;
    return 0;
}