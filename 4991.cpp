#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int w, h;
vector<vector<char>> MAP;
vector<pair<int, int>> toClean;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool IsInside(int y, int x)
{
    if (y >= 0 && y < h && x >= 0 && x < w)
        return true;
    return false;
}
void bfs(int y, int x, vector<vector<vector<int>>> &dist)
{
    vector<vector<int>> tempDist(h, vector<int>(w, -1));
    tempDist[y][x] = 0;
    queue<pair<int, int>> q;
    q.push({y, x});

    while (!q.empty())
    {
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny=hy+dir[i].first;
            int nx=hx+dir[i].second;

            if(!IsInside(ny,nx))continue;
            if(tempDist[ny][nx]!=-1)continue;
            if(MAP[ny][nx]=='x')continue;
            q.push({ny,nx});
            tempDist[ny][nx]=tempDist[hy][hx]+1;
        }
    }
    dist.push_back(tempDist);
}
void Solve()
{
    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            return;
        
        MAP.resize(h, vector<char>(w));

        for (int i = 0; i < h; i++)
        {
            string temp;
            cin >> temp;
            for (int j = 0; j < w; j++)
            {
                MAP[i][j] = temp[j];
                if (MAP[i][j] == 'o')
                    toClean.insert(toClean.begin(),{i,j});
                else if (MAP[i][j] == '*')
                    toClean.push_back({i, j});
            }
        }

        vector<vector<vector<int>>> dist;
        int length=toClean.size();
        for(int i=0; i<length ;i++)
            bfs(toClean[i].first,toClean[i].second,dist);
        

        // int height=dist.size();
        // for(int i=0; i<height; i++){
        //     cout<<toClean[i].first<<","<<toClean[i].second<<endl;
        //     for(int j=0; j<h; j++){
        //         for(int k=0; k<w; k++){
        //             cout<<dist[i][j][k]<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<"-----------------------------------------------"<<endl;
        // }

        vector<int> idx;
        for(int i=0; i<length; i++)
            idx.push_back(i);

        int ret=1e9;
        do{
            int sum=0;
            int hc=0;
            bool flag=true;

            // for(int i=1; i<length; i++)
            //     cout<<toClean[idx[i]].first<<", "<<toClean[idx[i]].second<<" ";
            // cout<<endl;

            for(int i=1; i<length; i++){
                if(dist[hc][toClean[idx[i]].first][toClean[idx[i]].second]==-1){
                    flag=false;
                    break;
                }
                sum+=dist[hc][toClean[idx[i]].first][toClean[idx[i]].second];
                hc=idx[i];
            }
            if(flag)
                ret=min(ret,sum);
        }while(next_permutation(idx.begin()+1,idx.end()));

        if(ret==1e9)
            cout<<-1<<endl;
        else
            cout<<ret<<endl;

        for (int i = 0; i < h; i++)
            MAP[i].clear();

        MAP.clear();
        toClean.clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}


// for(int i=0; i<h; i++){
//     for(int j=0; j<w; j++){
//         cout<<MAP[i][j]<<" ";
//     }
//     cout<<endl;
// }
// cout<<"-----------------------------------------------"<<endl;