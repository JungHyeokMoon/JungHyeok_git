// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;

// int n, m, k; //n*n땅,
// vector<vector<int>> Start;
// vector<vector<int>> Nutrient;
// vector<int> Tree[10][10];
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// void Input()
// {
//     cin >> n >> m >> k;
//     Start.resize(n, vector<int>(n, 5));
//     Nutrient.resize(n, vector<int>(n));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> Nutrient[i][j];
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         int y, x, z;
//         cin >> y >> x >> z;
//         y--;
//         x--;
//         Tree[y][x].push_back(z);
//     }
// }
// void Winter()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             Start[i][j] += Nutrient[i][j];
//         }
//     }
// }
// bool isinside(int y, int x)
// {
//     if (y >= 0 && y < n && x >= 0 && x < n)
//     {
//         return true;
//     }
//     return false;
// }

// void Output()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << Start[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }
// void SpringAndSummer()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (Tree[i][j].size() == 0)
//                 continue;

//             sort(Tree[i][j].begin(), Tree[i][j].end());
//             int length = Tree[i][j].size();
//             vector<int> temp;
//             int dieenergy=0;
//             for (int k = 0; k < length; k++)
//             {
//                 int age = Tree[i][j][k];

//                 if (Start[i][j] >= age)
//                 {
//                     Start[i][j] -= age;
//                     age++;
//                     temp.push_back(age);
//                 }
//                 else
//                 {
//                     dieenergy+=(age/2);
//                 }
//             }
//             Tree[i][j].clear();
//             int templength = temp.size();
//             for (int k = 0; k < templength; k++)
//             {
//                 Tree[i][j].push_back(temp[k]);
//             }
//             Start[i][j]+=dieenergy;
//         }
//     }
// }
// void Fall()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (Tree[i][j].size() == 0)
//                 continue;
//             int length = Tree[i][j].size();
//             for (int k = 0; k < length; k++)
//             {
//                 int age = Tree[i][j][k];
//                 if (!(age % 5))
//                 {
//                     for (int l = 0; l < 8; l++)
//                     {
//                         int ny = i + dy[l];
//                         int nx = j + dx[l];
//                         if (!isinside(ny, nx))
//                             continue;
//                         Tree[ny][nx].push_back(1);
//                     }
//                 }
//             }
//         }
//     }
// }
// void Solve()
// {
//     for (int s = 0; s < k; s++)
//     {
//         SpringAndSummer();
//         Fall();
//         Winter(); //겨울
//     }
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cnt += Tree[i][j].size();
//         }
//     }
//     cout << cnt;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Input();
//     Solve();
//     return 0;
// }


// //시간초과코드
// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;

// int n,m,k;//n*n땅,
// vector<vector<int>> Start;
// vector<vector<int>> Nutrient;
// vector<int> Tree[10][10]; 
// const int dy[8]={-1,-1,-1,0,0,1,1,1};
// const int dx[8]={-1,0,1,-1,1,-1,0,1};
// void Input(){
//     cin>>n>>m>>k;
//     Start.resize(n,vector<int>(n,5));
//     Nutrient.resize(n,vector<int>(n));
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cin>>Nutrient[i][j];
//         }
//     }
//     for(int i=0; i<m; i++){
//         int y,x,z;
//         cin>>y>>x>>z;
//         y--;
//         x--;
//         Tree[y][x].push_back(z);
//     }
// }
// void Feed(){
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             Start[i][j]+=Nutrient[i][j];
//         }
//     }
// }
// bool isinside(int y,int x){
//     if(y>=0 && y<n && x>=0 && x<n){
//         return true;
//     }
//     return false;
// }

// void Output(){
//     for(int i=0; i<n;i++){
//         for(int j=0; j<n; j++){
//             cout<<Start[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }

// void Solve(){
//     for(int s=0; s<k; s++){
//         queue<pair<pair<int,int>,int>> LiveTree;
//         queue<pair<pair<int,int>,int>> DeadTree;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n ; j++){
//                 if(Tree[i][j].size()==0)continue;

//                 sort(Tree[i][j].begin(),Tree[i][j].end());
//                 int length=Tree[i][j].size();
//                 for(int k=0; k<length; k++){
//                     int age=Tree[i][j][k];

//                     if(Start[i][j]>=age){
//                         Start[i][j]-=age;
//                         age++;
//                         LiveTree.push({{i,j},age});
//                     }
//                     else{
//                         DeadTree.push({{i,j},age});
//                     }
//                 }
//                 Tree[i][j].clear();
//             }
//         }//봄
//         while(!LiveTree.empty()){
//             pair<pair<int,int>,int> p=LiveTree.front();
//             int y=p.first.first;
//             int x=p.first.second;
//             int age=p.second;
//             LiveTree.pop();
//             Tree[y][x].push_back(age);
//             for(int i=0; i<8; i++){
//                 int ny=y+dy[i];
//                 int nx=x+dx[i];
//                 if(!isinside(ny,nx))continue;
//                 if(!(age%5)){
//                     Tree[ny][nx].push_back(1);
//                 }
//             }
//         }
//         while(!DeadTree.empty()){
//             pair<pair<int,int>,int> p=DeadTree.front();
//             int y=p.first.first;
//             int x=p.first.second;
//             int age=p.second;
//             DeadTree.pop();
//             Start[y][x]+=(age/2);
//         }
//         Feed();//겨울
//     }
//     int cnt=0;
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<n; j++){
//             cnt+=Tree[i][j].size();
//         }
//     }
//     cout<<cnt;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Input();
//     Solve();
//     return 0;
// }


#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
pair<int,int> dir[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int n,m,k;
vector<vector<int>> nutrient;
vector<vector<int>> supply;
vector<vector<vector<int>>> tree;
void Init(){
    cin>>n>>m>>k;
    nutrient.resize(n,vector<int>(n,5));
    supply.resize(n,vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>supply[i][j];
    
    
    tree.resize(n,vector<vector<int>>(n));
    for(int i=0; i<m; i++){
        int y,x,z;
        cin>>y>>x>>z;
        tree[y-1][x-1].push_back(z);
    }
    
}
bool isInside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n)
        return true;
    return false;
}
int Output(){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cnt+=tree[i][j].size();
        }
    }
    return cnt;
}
void SpringAndSummer(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!tree[i][j].empty()){
                sort(tree[i][j].begin(),tree[i][j].end());
                int length=tree[i][j].size();
                bool flag=false;
                for(int k=0; k<length; k++){
                    if(tree[i][j][k]<=nutrient[i][j]){
                        nutrient[i][j]-=tree[i][j][k];
                        tree[i][j][k]++;
                    }
                    else{
                        flag=true;
                        for(int l=length-1; l>=k; l--){
                            nutrient[i][j]+=(tree[i][j][l])/2;
                            tree[i][j].pop_back();
                        }
                    }
                    if(flag)
                        break;
                }
            }
        }
    }
}
void Autumn(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int length=tree[i][j].size();
            for(int k=0; k<length; k++){
                if(tree[i][j][k]%5==0){
                    for(int l=0; l<8; l++){
                        int ny=i+dir[l].first;
                        int nx=j+dir[l].second;
                        if(!isInside(ny,nx))continue;
                        tree[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}
void Winter(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            nutrient[i][j]+=supply[i][j];
}
void Solve(){
    for(int i=0; i<k; i++){
        SpringAndSummer();
        Autumn();
        Winter();
    }
    cout<<Output()<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    Solve();
    return 0;
}

void Test(){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<nutrient[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!tree[i][j].empty()){
                int length=tree[i][j].size();
                cout<<i<<", "<<j<<": ";
                for(int k=0; k<length; k++)
                    cout<<tree[i][j][k]<<" ";
                cout<<endl;
            }
        }
        cout<<endl;
    }
}