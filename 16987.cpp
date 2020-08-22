// #include <bits/stdc++.h>
// using namespace std;
// int n;
// vector<pair<int,int>> v;
// int ret=-987654321;
// int cnt=0;
// void solve(int idx){
//     if(idx>=n){
//         int cnt=0;
//         for(int i=0; i<n; i++){
//             if(v[i].first<=0){
//                 cnt++;
//             }
//         }
//         ret=max(ret,cnt);
//         return ;
//     }
//     if(v[idx].first<=0){
//         solve(idx+1);
//         return ;
//     }
//     bool flag=true;

//     for(int i=0; i<n; i++){
//         if(i==idx|| v[i].first<=0)continue;
//         flag=false;
//         v[i].first-=v[idx].second;
//         v[idx].first-=v[i].second;

//         solve(idx+1);

//         v[i].first+=v[idx].second;
//         v[idx].first+=v[i].second;

//     }
//     if(flag)solve(idx+1);
// }

// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>n;
//     v.resize(n);
//     for(int i=0; i<n ; i++){
//         cin>>v[i].first>>v[i].second;//내구도, 무게
//     }

//     solve(0);
//     cout<<ret<<"\n";
// }
// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n;
// vector<pair<int, int>> arr; //계란 내구도, 무게
// int ret = 0;
// void Init()
// {
//     cin >> n;
//     arr.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].first >> arr[i].second;
//     }
// }
// void EggBreak(int idx)
// {
//     if (idx == n)
//     {
//         int Breaked = 0;
//         for (int i = 0; i < arr.size(); i++)
//         {
//             if (arr[i].first <= 0)
//             {
//                 Breaked++;
//             }
//         }
//         ret = max(ret, Breaked);
//         return;
//     }

//     if (arr[idx].first <= 0) //들고있는 계란의 내구도가 0이하라 깨져있을경우 다음으로넘김
//     {
//         EggBreak(idx + 1);
//         return;
//     }
//     bool flag = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (i == idx || arr[i].first <= 0)
//             continue;

//         flag = true;                     //하나라도 치는게있을경우
//         arr[idx].first -= arr[i].second; //들고있는 계란의 내구도는 치려는 계란의 무게만큼빠짐
//         arr[i].first -= arr[idx].second; //들이박아지는 계란의 내구도는 들고있는 계란의 무게만큼빠짐
//         EggBreak(idx + 1);               //한칸재귀
//         arr[idx].first += arr[i].second; //1에대한 다시 되돌려놓기
//         arr[i].first += arr[idx].second; //2에대한 돌려놓기
//     }
//     if (!flag) //하나라도 치는게없는경우 다음칸으로 넘기기
//         EggBreak(idx + 1);
// }
// void Solve()
// {
//     EggBreak(0);
//     cout << ret << endl;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Init();
//     Solve();
//     return 0;
// }


#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<pair<int,int>> v;
int ret=0;
void Init(){
    cin>>n;
    v.resize(n);

    for(int i=0; i<n; i++)
        cin>>v[i].first>>v[i].second; //내구도 무게
}
void EggBreak(int idx){
    if(idx==n){
        int temp=0;
        for(int i=0; i<n; i++){
            if(v[i].first<=0)
                temp++;
        }
        ret=max(ret,temp);
        return ;
    }

    if(v[idx].first<=0){
        EggBreak(idx+1);
        return ;
    }
    bool flag=false;
    for(int i=0; i<n; i++){
        
        if(idx==i || v[i].first<=0)continue;

        flag=true;
        v[idx].first-=v[i].second;
        v[i].first-=v[idx].second;
        EggBreak(idx+1);
        v[i].first+=v[idx].second;
        v[idx].first+=v[i].second;
    }
    if(!flag)
        EggBreak(idx+1);
}
void Solve(){
    EggBreak(0);
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