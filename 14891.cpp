// #include <bits/stdc++.h>
// using namespace std;

// int gear[4][8]; //위가 0부터 시계방향으로 7까지인덱스 0번톱니바퀴2 1번톱니바퀴 6 || (1,2) <->2,6 || (2,2)<->(3,6) n극은 0 s극이면 1
// int k;
// int ret=0;
// void getscore(){
//     for(int i=0; i<4; i++){
//         if(gear[i][0]==1){
//             ret+=pow(2,i);
//         }
//     }
//     //cout<<"ret : "<<ret<<"\n";
// }
// void rotation(int num,int direc){
//     if(direc==1){
//         int temp=gear[num][7];
//         for(int i=7; i>=1; i--){
//             gear[num][i]=gear[num][i-1];
//         }
//         gear[num][0]=temp;
//     }//시계방향
//     else {
//         int temp=gear[num][0];
//         for(int i=0; i<=6; i++){
//             gear[num][i]=gear[num][i+1];
//         }
//         gear[num][7]=temp;
//     }//반시계방향
// }
// int reversedirection(int direc){
//     if(direc==1)return -1;
//     else return 1;
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     for(int i=0; i<4; i++){
//         string temp;
//         cin>>temp;
//         for(int j=0; j<8; j++){
//             gear[i][j]=temp[j]-'0';
//         }
//     }

//     cin>>k;
//     for(int i=0; i<k; i++){
//         int num;
//         int direction;
//         cin>>num>>direction; //num은 톱니바퀴번호 direction은 방향 1 시계방향 -1 반시계방향
//         num=num-1;
//         int rd=reversedirection(direction);
//         if(num==0){
//             if(gear[0][2]!=gear[1][6]){
//                 if(gear[1][2]!=gear[2][6]){
//                     if(gear[2][2]!=gear[3][6]){
//                         rotation(num,direction);
//                         rotation(num+1,rd);
//                         rotation(num+2,direction);
//                         rotation(num+3,rd);
//                     }
//                     else{
//                         rotation(num,direction);
//                         rotation(num+1,rd);
//                         rotation(num+2,direction);
//                     }
//                 }
//                 else{
//                     rotation(num,direction);
//                     rotation(num+1,rd);
//                 }
//             }
//             else{
//                 rotation(0,direction);
//             }//다르면 0번만 회전시킴
//         }
//         else if(num==1){
//             if(gear[0][2]!=gear[1][6]){
//                 rotation(num-1,rd);
//             }
//             if(gear[1][2]!=gear[2][6]){
//                 if(gear[2][2]!=gear[3][6]){
//                     rotation(num,direction);
//                     rotation(num+1,rd);
//                     rotation(num+2,direction);
//                 }
//                 else{
//                     rotation(num,direction);
//                     rotation(num+1,rd);
//                 }
//             }
//             else{
//                 rotation(num,direction);
//             }
//         }
//         else if(num==2){
//             if(gear[2][2]!=gear[3][6]){
//                 rotation(num+1,rd);
//             }
//             if(gear[2][6]!=gear[1][2]){
//                 if(gear[1][6]!=gear[0][2]){
//                     rotation(num,direction);
//                     rotation(num-1,rd);
//                     rotation(num-2,direction);
//                 }
//                 else{
//                     rotation(num,direction);
//                     rotation(num-1,rd);
//                 }
//             }
//             else{
//                 rotation(num,direction);
//             }
//         }
//         else{
//             if(gear[3][6]!=gear[2][2]){
//                 if(gear[2][6]!=gear[1][2]){
//                     if(gear[1][6]!=gear[0][2]){
//                         rotation(num,direction);
//                         rotation(num-1,rd);
//                         rotation(num-2,direction);
//                         rotation(num-3,rd);
//                     }
//                     else{
//                         rotation(num,direction);
//                         rotation(num-1,rd);
//                         rotation(num-2,direction);
//                     }

//                 }
//                 else{
//                     rotation(num,direction);
//                     rotation(num-1,rd);
//                 }
//             }
//             else{
//                 rotation(num,direction);
//             }
//         }

//     }
//     getscore();
//     cout<<ret<<"\n";
//     //같은극이면 가만히있음 ,다른극이면 회전의 반대방향으로 회전한다.
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<vector<int>> gear;
int k;
vector<pair<int, int>> rotation; //n극은 0, s극은 1
void Init()
{
    gear.resize(4, vector<int>(8));

    for (int i = 0; i < 4; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < 8; j++)
        {
            gear[i][j] = temp[j] - '0';
        }
    }

    cin >> k;
    rotation.resize(k);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        // cin >> rotation[i].first >> rotation[i].second; //1 시계방향회전 -1 반시계방향회전
        rotation[i].first = a - 1;
        rotation[i].second = b;
    }
}
void Output()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << gear[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void Self_Rotate(int idx, int dir)
{
    int temp = gear[idx][0];
    //1 시계방향
    if (dir == 1)
    {
        for (int i = 8; i >= 2; i--)
            gear[idx][i % 8] = gear[idx][i - 1];
        gear[idx][1] = temp;
    }
    else
    { //-1 반시계방향

        for (int i = 0; i <= 6; i++)
            gear[idx][i] = gear[idx][i + 1];
        gear[idx][7] = temp;
    }
}
void Rotation(int idx, int dir, vector<bool> &visited)
{
    if (idx < 0 || idx >= 4)
        return;

    if (idx == 0)
    {
        if (gear[idx][2] != gear[idx + 1][6])
        {
            if (!visited[idx + 1])
            {
                visited[idx + 1] = true;
                Rotation(idx + 1, dir * -1, visited);
            }
        }
    }
    else if (idx == 1 || idx == 2)
    {
        if (gear[idx][2] != gear[idx + 1][6])
        {
            if (!visited[idx + 1])
            {
                visited[idx + 1] = true;
                Rotation(idx + 1, dir * -1, visited);
            }
        }
        if (gear[idx][6] != gear[idx - 1][2])
        {
            if (!visited[idx - 1])
            {
                visited[idx - 1] = true;
                // cout << "hidx : " << idx << "nidx : " << idx - 1 << "ndir : " << dir * -1 << endl;
                Rotation(idx - 1, dir * -1, visited);
            }
        }
    }
    else
    {
        if (gear[idx][6] != gear[idx - 1][2])
        {
            if (!visited[idx - 1])
            {
                visited[idx - 1] = true;
                Rotation(idx - 1, dir * -1, visited);
            }
        }
    }
    Self_Rotate(idx, dir);
}
int getScore()
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum += (gear[i][0] << i);

    return sum;
}
void Solve()
{
    for (int i = 0; i < k; i++)
    {
        vector<bool> visited(4, false);
        visited[rotation[i].first] = true;
        Rotation(rotation[i].first, rotation[i].second, visited);
        // Output();
    }
    cout << getScore() << endl;
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