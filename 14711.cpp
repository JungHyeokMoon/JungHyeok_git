#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<vector<char>> puzzle;
const int dy[3]={0,-1,0};
const int dx[3]={-1,0,1};
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n){
        return true;
    }
    return false;
}
void Input()
{
    cin >> n;
    puzzle.resize(n, vector<char>(n)); //#은 검은색 화면이 위를향하도록 , .은 흰색면이 위를향하도록
    for (int i = 0; i < n; i++)
    {
        cin >> puzzle[0][i];
    }

}
void Solve()
{
    for(int i=1; i<n ; i++){
        
        for(int j=0; j<n; j++){
            int cnt=0;
            for(int k=0; k<3; k++){
                int py=i-1+dy[k]; //한칸위의 좌 상 우 살펴봐야함
                int px=j+dx[k];
                if(!isinside(py,px))continue;
                if(puzzle[py][px]=='#')cnt++;
            }
            if(cnt%2){
                puzzle[i][j]='#';
            }
            else{
                puzzle[i][j]='.';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<puzzle[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}