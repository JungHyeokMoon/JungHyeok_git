#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char delimeter){
    vector<string> ret;
    int strLength=str.size();
    string temp;
    for(int i=0; i<strLength; i++){
        if(str[i]==delimeter){
            ret.push_back(temp);
            temp="";
        }else
            temp.push_back(str[i]);
    }
    ret.push_back(temp);

    return ret;
}

vector<int> solution(vector<string> operations) {
    map<int,int> m;
    vector<int> answer;

    for(auto i :operations){
        vector<string> line = split(i,' ');
        string op=line[0];
        int Num=stoi(line[1]);
        // cout<<op<<" "<<Num<<endl;
        if(op=="I")
            m[Num]++;
        else if(op=="D"){
            if(m.empty()) continue;
            if(Num==-1){
                auto j=m.begin();
                if(m[j->first]==1)
                    m.erase(j->first);
                else
                    m[j->first]--;
                
            }else{
                auto j=m.rbegin();
                if(m[j->first]==1)
                    m.erase(j->first);
                else
                    m[j->first]--;
            }
        }
        
    }

    if(m.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        auto i=m.rbegin();
        answer.push_back(i->first);
        auto j=m.begin();
        answer.push_back(j->first);
    }
    return answer;
}

int main(){
    vector<string> operations;
    operations.push_back("I 16");
    operations.push_back("I -5643");
    operations.push_back("D -1");
    operations.push_back("D 1");
    operations.push_back("D 1");
    operations.push_back("I 123");
    operations.push_back("D -1");

    vector<int> Answer=solution(operations);
    for(auto i :Answer)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

