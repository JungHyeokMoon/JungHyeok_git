#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<int> grade;
void Init(){
    cin>>n;
    grade.resize(n);
    for(auto &i :grade)
        cin>>i;
}
void Solve(){
    if(n==0){
        cout<<0<<endl;
        return ;
    }
    sort(grade.begin(),grade.end());
    int sum=0;
    int temp=round(n*0.15);

    for(int i=temp; i<n-temp;i++)
        sum+=grade[i];
    
    cout<<round(sum/(double)(n-temp*2))<<endl;
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