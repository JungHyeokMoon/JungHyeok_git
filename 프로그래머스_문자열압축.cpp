#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = s.size();
    int length=answer/2;
    for(int i=1; i<=length; i++){
        string prev=s.substr(0,i);
        cout<<prev<<endl;
        int j=i;
        int cnt=1;
        vector<pair<string ,int>> v;
        string cur;
        while(j<s.size()){
            cur=s.substr(j,i);
            if(prev==cur)
                cnt++;
            else{
                v.push_back({prev,cnt});
                prev=cur;
                cnt=1;
            }
            // cout<<cur<<" ";
            j+=i;
        }
        if(prev==cur){
            v.push_back({prev,cnt});
        }else
            v.push_back({prev,1});
        string temp;
        for(auto j: v){
            if(j.second!=1)
                temp+=to_string(j.second);
            temp+=j.first;
        }
        // cout<<"temp: "<<temp;
        // cout<<endl;
        
        if(answer>temp.size())
            answer=temp.size();
    }
    return answer;
}

int main(){
    cout<<"Answer: "<<solution("aabbaccc")<<endl;
    cout<<"Answer: "<<solution("ababcdcdababcdcd")<<endl;
    cout<<"Answer: "<<solution("abcabcdede")<<endl;
    cout<<"Answer: "<<solution("abcabcabcabcdededededede")<<endl;
    cout<<"Answer: "<<solution("xababcdcdababcdcd")<<endl;
    // solution("ababcdcdababcdcd");
    // solution("abcabcdede");
    // solution("abcabcabcabcdededededede");
    // solution("xababcdcdababcdcd");
    return 0;
}