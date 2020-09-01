#include <bits/stdc++.h>
#define Enter "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù."
#define Leave "´ÔÀÌ ³ª°¬½À´Ï´Ù."
using namespace std;
map<string,string> m;
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
vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    int recordLength=record.size();
    vector<pair<map<string,string>::iterator, string>> v;
    for(int i=0; i<recordLength ; i++){
        vector<string> temp=split(record[i],' ');
        string cmd=temp[0];
        string userId=temp[1];
        string nickName;
        if(cmd!="Leave")
            nickName=temp[2];
        
        if(cmd=="Enter"){
            m[userId]=nickName;
            v.push_back({m.find(userId),Enter});
        }else if(cmd=="Change")
            m[userId]=nickName;
        else{//Leave
            v.push_back({m.find(userId),Leave});
            // m.erase(userId);
        }
    }
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].first->second+v[i].second);
    }
    return answer;
}

int main(){
    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");
    vector<string>Answer=solution(record);
    
    for(auto i : Answer)
        cout<<i<<endl;
    return 0;
}