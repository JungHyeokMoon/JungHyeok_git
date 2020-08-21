#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,k;
vector<vector<int>> input;
vector<vector<int>> rsp;

vector<vector<int>> temp;
vector<bool>combi;


void Init(){
    cin>>n>>k;
    input.resize(n,vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0 ;j<n; j++)
            cin>>input[i][j];

    rsp.resize(3,vector<int>(20));
    for(int i=1; i<3; i++){
        for(int j=0; j<20; j++){
            // cin>>rsp[i][j];
            int temp;
            cin>>temp;
            rsp[i][j]=temp-1;
        }
    }
    for(int i=0; i<n; i++)
        rsp[0][i]=i;
}
bool Match(){
    int wins[3]={0,0,0};
    int idx[3]={0,0,0};
    int p1=0, p2=1, p3=2;
    while(1){
        if(p1>p2)swap(p1,p2);

        if(p1==0 && idx[p1]==n)break;
        if(idx[p1]==20 || idx[p2]==20)break;
        int a=rsp[p1][idx[p1]++];
        int b=rsp[p2][idx[p2]++];

        if(input[a][b]==2){
            wins[p1]++; 
            swap(p2,p3);
            if(wins[p1]==k)break;
        } //앞에사람이 이김
        else{
            wins[p2]++;
            swap(p1,p3);
            if(wins[p2]==k)break;
        }//뒤에사람이 이김
    }
    return wins[0]>=k;
}
void Solve(){
    do{
        if(Match()){
            cout<<1<<endl;
            return ;
        }
    }while(next_permutation(rsp[0].begin(),rsp[0].begin()+n));
    cout<<0<<endl; 
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