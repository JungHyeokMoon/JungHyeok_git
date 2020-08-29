#include <bits/stdc++.h>
using namespace std;
map<int,int> m;

void InsertMap(string &s){
    string temp;
    int length=s.size();
    stack<char> bracket;
    for(int i=1; i<length-1; i++){
        if(s[i]=='{')
            bracket.push(s[i]);
        else if(s[i]=='}'){
            m[stoi(temp)]++;
            // cout<<temp<<endl;
            temp="";
            bracket.pop();
        }
        else if(s[i]==','){
            if(bracket.empty())continue;
            else{
                m[stoi(temp)]++;
                // cout<<temp<<endl;
                temp="";
            }
        }else{
            temp.push_back(s[i]);
        }
    }  
    // for(auto i: m)
    //     cout<<i.first<<" "<<i.second<<endl;
}
bool Compare(pair<int,int> &a, pair<int,int> & b){
    if(a.second>b.second)
        return true;
    else
        return false;
}
vector<int> solution(string s) {
    vector<int> answer;
    InsertMap(s);
    vector<pair<int,int>> v;
    for(auto i: m)
        v.push_back(i);
    
    // cout<<"-----------"<<endl;
    // for(auto i: v)
    //     cout<<i.first<<" "<<i.second<<endl;
    

    // cout<<"-----------"<<endl;
    sort(v.begin(),v.end(),Compare);
    for(auto i: v){
        // cout<<i.first<<" "<<i.second<<endl;
        answer.push_back(i.first);
    }
    
    
    return answer;
}

int main()
{
    vector<int> Answer=solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    cout<<"[";
    for(int i=0; i<Answer.size()-1; i++)
        cout<<Answer[i]<<", ";
    cout<<Answer[Answer.size()-1];
    cout<<"]";
    return 0;
}
