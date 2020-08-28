#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string S, E, Q;
vector<string> split(string str,char delimeter){
    vector<string> newVector;
    
    string temp;
    for(int i=0; i<str.size(); i++){
        if(str[i]!=delimeter){
            temp.push_back(str[i]);
        }
        else{
            newVector.push_back(temp);
            temp="";
        }
    }
    newVector.push_back(temp);
    return newVector;
}
class Time{
    private:
        int hour;
        int minute;
    
    public:
        Time(string time){
            vector<string> temp=split(time,':');
            hour=stoi(temp[0]);
            minute=stoi(temp[1]);
        }

        void Output(){
            cout<<hour<<" "<<minute<<endl;
        }
        bool Compare(Time & t1){
            if(hour<t1.hour){
                return true;
            }
            else if(hour==t1.hour){
                if(minute<=t1.minute)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
};
void Solve()
{
    cin >> S >> E >> Q;
    Time startTime(S);
    Time endTime(E);
    Time qTime(Q);
    
    string time, nickname;
    set<string> In;
    set<string> Out;
    while (cin >> time >> nickname)
    {   
        Time tempTime(time);
        if(tempTime.Compare(startTime))
            In.insert(nickname);
        
        if(endTime.Compare(tempTime) && tempTime.Compare(qTime))
            Out.insert(nickname);
    }

    int cnt=0;
    for(auto i :In){
        if(Out.find(i)!=Out.end())
            cnt++;
    }
    cout<<cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}