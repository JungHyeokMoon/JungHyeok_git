// #include <bits/stdc++.h>
// using namespace std;

// int n,m;
// int y,x;
// int k;
// int MAP[20][20];
// int command[1000];
// int dice[6]; //0이 위 2이동쪽 1가 북쪽 3가 서쪽 4가 남쪽 5이 아래쪽
// bool isinside(int hx, int hy){
//     if(hx>=0 && hx<n && hy>=0 && hy<m){
//         return true;
//     }
//     return false;
// }

// void move(int cmd){
//     //cout<<"cmd : "<<cmd<<" , "<<" x: "<<x<<" , "<<"y : "<<y<<"\n";
//     if(cmd==1){
//         y=y+1;
//         if(!isinside(x,y)){
//             y=y-1;
//             return ;
//         }
//         int temp=dice[3];
//         dice[3]=dice[5];
//         dice[5]=dice[2];
//         dice[2]=dice[0];
//         dice[0]=temp;
//     }//1동쪽
//     else if(cmd==2){
//         y=y-1;
//         if(!isinside(x,y)){
//             y=y+1;
//             return ;
//         }
//         int temp=dice[2];
//         dice[2]=dice[5];
//         dice[5]=dice[3];
//         dice[3]=dice[0];
//         dice[0]=temp;
//     }//2 서쪽
//     else if(cmd==3){
//         x=x-1;
//         if(!isinside(x,y)){
//             x=x+1;
//             return ;
//         }
//         int temp=dice[0];
//         dice[0]=dice[4];
//         dice[4]=dice[5];
//         dice[5]=dice[1];
//         dice[1]=temp;
//     }//3 북쪽
//     else{
//         x=x+1;
//         if(!isinside(x,y)){
//             x=x-1;
//             return ;
//         }
//         int temp=dice[4];
//         dice[4]=dice[0];
//         dice[0]=dice[1];
//         dice[1]=dice[5];
//         dice[5]=temp;
//     }//4 남쪽
//     if(!MAP[x][y]){
//         MAP[x][y]=dice[5];
//     }
//     else{
//         dice[5]=MAP[x][y];
//         MAP[x][y]=0;
//     }
//     cout<<dice[0]<<"\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);
//     cin>>n>>m>>x>>y>>k; //x가 북쪽에서 얼마나 떨어져있는지 y가 서쪽에서 얼마나 떨어져있는지
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<m; j++){
//             cin>>MAP[i][j];
//         }
//     }
//     for(int i=0; i<k; i++){
//         int num;
//         cin>>num;
//         move(num);
//     }

//     return 0;

// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m, y, x, k;
vector<vector<int>> MAP;
pair<int, int> dir[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<int> cmd;
int dice[4][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};
void diceOutput()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << dice[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Init()
{
    cin >> n >> m >> y >> x >> k;
    MAP.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> MAP[i][j];

    cmd.resize(k);
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        cmd[i] = d - 1;
    }
}
bool isInside(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < m)
        return true;
    return false;
}
void rotate(int d)
{
    if (d == 0)
    { //동쪽
        int temp = dice[3][1];
        dice[3][1] = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = temp;
    }
    else if (d == 1)
    { //서쪽
        int temp = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = dice[3][1];
        dice[3][1] = temp;
    }
    else if (d == 2)
    { //북쪽
        int temp = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = temp;
    }
    else
    {
        int temp = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = temp;
    }
}

void Solve()
{
    for (int i = 0; i < k; i++)
    {
        int d = cmd[i];
        if (isInside(y + dir[d].first, x + dir[d].second))
        { //이동할수있는경우
            y = y + dir[d].first;
            x = x + dir[d].second;

            //주사위 회전시키고
            rotate(d);

            if (MAP[y][x] == 0)
            {
                //주사위 바닥면에 쓰여있는수가 MAP에 복사됨
                MAP[y][x] = dice[3][1];
            }
            else
            {
                //MAP에 쓰여있는수가 주사위바닥면에복사됨
                dice[3][1] = MAP[y][x];
                //칸에 쓰여 있는 수가 0이된다.
                MAP[y][x] = 0;
            }
            // diceOutput();
            //출력
            cout << dice[1][1] << endl;
        }
    }
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