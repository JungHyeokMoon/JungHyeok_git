// #include <bits/stdc++.h>
// using namespace std;
// int n,l;
// int tilt[100][100];
// int ret=0;
// bool check(int ,bool);
// void solve(int cnt){
//     if(cnt==n){
//         cout<<ret<<"\n";
//         return ;
//     }
    
//     if(check(cnt,false))ret++; //가로체크
//     if(check(cnt,true))ret++; //세로체크
//     solve(cnt+1);
//     return ;
// }
// bool make_road1(int i, int j){
    
//     int compare=tilt[i][j+1];
//     for(int k=j+1; k<j+1+l; k++){
//         if(compare!=tilt[i][k])return false;
//     }

//     return true;
// }



// bool make_road2(int i, int j){
//     int compare=tilt[i+1][j];
//     for(int k=i+1; k<i+1+l; k++){
//         if(compare!=tilt[k][j])return false;
//     }
//     return true;
// }
// bool check(int idx,bool flag){
//     int length=1;
//     if(flag){
//         for(int i=0; i<n-1; i++){
//             if(tilt[idx][i]==tilt[idx][i+1])length++;
//             else if(tilt[idx][i]==tilt[idx][i+1]+1){
//                 if(make_road1(idx,i)){
//                     i=i+l-1;
//                     length=0;
//                 }
//                 else{
//                     return false;
//                 }
//             }//앞에것이 더 높을때
//             else if(tilt[idx][i]+1==tilt[idx][i+1]){
//                 if(length>=l){
//                     length=1;
//                 }
//                 else{
//                     return false;
//                 }
//             }//뒤에것이 더 높을때
//             else if(abs(tilt[idx][i]-tilt[idx][i+1])>=2){
//                 return false;
//             } //2보다크면 그냥 false
            
//         }
//     }
//     else{
//         for(int i=0; i<n-1; i++){
//             if(tilt[i][idx]==tilt[i+1][idx])length++;
//             else if(tilt[i][idx]==tilt[i+1][idx]+1){
//                 if(make_road2(i,idx)){
//                     i=i+l-1;
//                     length=0;
//                 }
//                 else{
//                     return false;
//                 }
//             }//앞에껏이 더 높을때
//             else if(tilt[i][idx]+1==tilt[i+1][idx]){
//                 if(length>=l){
//                     length=1;
//                 }
//                 else{
//                     return false;
//                 }
//             }//뒤에것이 더 높을때
//             else if(abs(tilt[i][idx]-tilt[i+1][idx])>=2){
//                 return false;
//             }//2차이나면 바로 false;
//         }
//     }


//     return true;//그냥평탄할경우
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>n>>l;

//     for(int i=0; i<n; i++){
//         for(int j=0; j< n ; j++){
//             cin>>tilt[i][j];
//         }
//     }
//     solve(0);
//     return 0;

// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,l;
vector<vector<int>> MAP;
int ret=0;
void Init(){
    cin>>n>>l;
    MAP.resize(n,vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>MAP[i][j];
}
bool GaroCheck(int row){
    vector<bool> equip(n,false);
    for(int i=0; i<n-1; i++){
        if(MAP[row][i]!=MAP[row][i+1]){
            if(MAP[row][i]<MAP[row][i+1]){
                if(i+1-l<0) return false;
                for(int j=i+1-l; j<=i; j++){
                    if(MAP[row][i+1]-MAP[row][j]==1 && equip[j]==false)
                        equip[j]=true;
                    //길이차가 1밖에 안나고 이미 설치가 되어있지않는경우
                    else
                        return false;
                }
            } // 경사로가 왼쪽으로 오르는방향으로
            else{
                if(i+l>=n)return false;
                for(int j=i+1; j<=i+l; j++){
                    if(MAP[row][i]-MAP[row][j]==1 && equip[j]==false)
                        equip[j]=true;
                    else
                        return false;
                }
            }//경사로가 아래쪽으로 내려가는방향으로 
        }
    }
    return true;
}
bool SeroCheck(int col){
    vector<bool> equip(n,false);
    for(int i=0; i<n-1; i++){
        if(MAP[i][col]!=MAP[i+1][col]){
            if(MAP[i][col]>MAP[i+1][col]){
                if(i+l>=n) return false;
                for(int j=i+1; j<=i+l; j++){
                    if(MAP[i][col]-MAP[j][col]==1 && equip[j]==false)
                        equip[j]=true;
                    else
                        return false;
                }
            }//위에서 아래로 내려가는 경사로
            else{
                if(i+1-l<0)return false;
                for(int j=i+1-l; j<=i; j++){
                    if(MAP[i+1][col]-MAP[j][col]==1 && equip[j]==false)
                        equip[j]=true;
                    else
                        return false;
                }
            }//아래에서 위로 올라가는 경사로
        }
    }
    return true;
}
void Solve(){
    for(int i=0; i<n; i++){
        if(GaroCheck(i))
            ret++;
        
        if(SeroCheck(i))
            ret++;
    }
    cout<<ret<<endl;
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