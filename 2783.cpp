#include <bits/stdc++.h>
using namespace std;
double X,Y;
int N;
//vector<pair<int,int>> samgak;
void Solve(){
    cin>>X>>Y; //Y그램당X원 ,1000그램 가격의 최저가
    double Temp=(X/Y)*1000;
    //cout<<"Temp : "<<Temp<<"\n";
    cin>>N;
    for(int i=0; i<N ; i++){
        double q,w;
        cin>>q>>w;
        double Temp2=(q/w)*1000;
        Temp=min(Temp,Temp2);
    }
    cout<<Temp<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}