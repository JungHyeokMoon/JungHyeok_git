#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;	
int n,m;	
vector<vector<int>> MAP;	
vector<pair<int,int>> chickenHouse;	
vector<pair<int,int>> temp;	
vector<pair<int,int>> house;	
vector<bool> visited;	
int chsize,hsize;	
int ret=987654321;	
void Input(){	
    cin>>n>>m;	
    MAP.resize(n,vector<int>(n));	
    for(int i=0; i<n; i++){	
        for(int j=0; j<n; j++){	
            cin>>MAP[i][j];	
            if(MAP[i][j]==1){	
                house.push_back({i,j});	
            }	
            else if(MAP[i][j]==2){	
                chickenHouse.push_back({i,j});	
            }	
        }	
    }	
    chsize=chickenHouse.size();	
    hsize=house.size();	
    // visited.resize(chickenHouse.size());	
    visited.resize(chsize);	
}	
int Cal(){	
    int sum=0;	
    int templength=temp.size();	
    for(int i=0; i<hsize; i++){	
        int tempdistance=987654321;	
        for(int j=0; j<templength; j++){	
            tempdistance=min(tempdistance,(abs(house[i].first-temp[j].first)+abs(house[i].second-temp[j].second)));	
        }	
        sum+=tempdistance;	
    }	
    return sum;	
}	
void MakeTemp(int cnt){	
    if(temp.size()==m){	
        ret=min(ret,Cal());	
        return ;	
    }	

    for(int i=cnt; i< chsize; i++){	
        if(!visited[i]){	
            temp.push_back(chickenHouse[i]);	
            visited[i]=true;	
            MakeTemp(i);	
            visited[i]=false;	
            temp.pop_back();	
        }	
    }	
}	
void Solve(){	
    MakeTemp(0);	
    cout<<ret<<endl;	
}	
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);	
    Input();	
    Solve();	
    return 0;	
} 