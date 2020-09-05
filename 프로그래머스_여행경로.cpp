#include <bits/stdc++.h>
using namespace std;
vector<string> answer;
vector<bool> visited;
bool dfs(string curNation, vector<vector<string>> & tickets,vector<string> &tmp,int cnt)
{
    tmp.push_back(curNation);
    if(cnt==tickets.size()){
        answer=tmp;
        return true;
    }

    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0]==curNation && visited[i]==false){
            visited[i]=true;
            if(dfs(tickets[i][1],tickets,tmp,cnt+1)) return true;
            visited[i]=false;
        }
    }
    tmp.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(),tickets.end());
    visited.resize(tickets.size());
    vector<string> tmp;
    dfs("ICN",tickets,tmp,0);
    return answer;
}
int main()
{
    cout<<"----------------------Answer---------------------"<<endl;
    // vector<string> Answer = solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}});
    // for (auto i : Answer)
    //     cout << i << " ";
    // cout << endl;
    // vector<string> Answer = solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}});
    // for(auto i :Answer)
    //     cout<<i <<" ";
    // cout<<endl;
    // vector<string> Answer = solution({{"ICN", "A"}, {"ICN", "B"}, {"B", "ICN"}});
    // for (auto i : Answer)
    //     cout << i << " ";
    // cout << endl;
    vector<string> Answer = solution({{"ICN", "A"}, {"A", "C"}, {"A", "D"},{"D","B"},{"B","A"}});
    for(auto i :Answer)
        cout<<i <<" ";
    cout<<endl;
    // vector<string> Answer = solution({{"ICN", "A"}, {"ICN", "A"}, {"A", "ICN"}});
    // for(auto i :Answer)
    //     cout<<i <<" ";
    // cout<<endl;
    return 0;
}

