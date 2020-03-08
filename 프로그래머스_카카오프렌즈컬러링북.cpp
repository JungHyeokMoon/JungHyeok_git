#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> visited;
vector<pair<int,int>> dy_dx;
int number_of_area;
int max_size_of_one_area;
vector<int> answer;
int sero;
int garo;
// void Init(int m, int n){
//     visited.resize(m);
//     for(int i=0; i<m; i++){
//         visited[i].resize(n,false);
//     }
//     dy_dx.resize(4);
//     dy_dx[0]={0,-1};
//     dy_dx[1]={-1,0};
//     dy_dx[2]={0,1};
//     dy_dx[3]={1,0};
//     number_of_area=0;
//     max_size_of_one_area=0;
//     sero=m;
//     garo=n;
// }
bool is_inside(int y, int x){
    if(y>=0 && y<sero && x>=0 && x<garo){
        return true;
    }
    return false;
}
void bfs(int y, int x,vector<vector<int>> & picture){
    visited[y][x]=true;
    queue<pair<int,int>> q;
    q.push({y,x});
    int size=0;
    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;
        int h_color=picture[hy][hx];
        size++;
        q.pop();

        for(int i=0; i<4; i++){
            int ny=hy+dy_dx[i].first;
            int nx=hx+dy_dx[i].second;
            if(!is_inside(ny,nx))continue;
            if(visited[ny][nx])continue;
            if(picture[ny][nx]==h_color){
                q.push({ny,nx});
                visited[ny][nx]=true;
            }

        }
    }
    max_size_of_one_area=max(max_size_of_one_area,size);
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    // Init(m,n);
    visited.clear();
     visited.resize(m);
    for(int i=0; i<m; i++){
        visited[i].resize(n,false);
    }
    dy_dx.clear();
    dy_dx.resize(4);
    dy_dx[0]={0,-1};
    dy_dx[1]={-1,0};
    dy_dx[2]={0,1};
    dy_dx[3]={1,0};
    number_of_area=0;
    max_size_of_one_area=0;
    sero=m;
    garo=n;
    answer.clear();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && picture[i][j]){
                number_of_area++;
                bfs(i,j,picture);
            }
        }
    }
    answer.push_back(number_of_area);
    answer.push_back(max_size_of_one_area);
    return answer;
}