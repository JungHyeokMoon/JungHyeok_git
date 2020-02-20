// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// int w,h,p,q,t;//w: 가로 h 세로 (p,q) 좌표 t:얼마동안움직일것인지
// int dx=1, dy=1;
// int d=0;
// int cnt=-1;
// void Input(){
//     cin>>w>>h>>p>>q>>t;
// }
// void Solve(int hx, int hy){
//     cnt++;
//     // cout<<"hx : "<<hx<<", hy : "<<hy<<endl;
//     if(cnt==t){
//         cout<<hx<<" "<<hy<<endl;
//         return ;
//     }
//     if(hx+dx>w||hx+dx<0){
//         dx=-dx;
//     }
//     if(hy+dy>h||hy+dy<0){
//         dy=-dy;
//     }
//     //y와 x를 
//     hx+=dx;
//     hy+=dy;  
//     Solve(hx,hy);

// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     Input();
//     Solve(p,q);
// }


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int w,h,p,q,t;//w: 가로 h 세로 (p,q) 좌표 t:얼마동안움직일것인지
void Input(){
    cin>>w>>h>>p>>q>>t;
}
void Solve(){
    int x=(p+t)/w;
    int y=(q+t)/h;

    if(x%2==0){
        p=(p+t)%w;
    }else{
        p=w-(p+t)%w;
    }
    if(y%2==0){
        q=(q+t)%h;
    }
    else{
        q=h-(q+t)%h;
    }
    cout<<p<<" "<<q<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();

    return 0;
}