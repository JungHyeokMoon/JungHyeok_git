#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
map<string ,int> m;
void Solve(){
    string input;
    int n=0;
    while(getline(cin,input)){
        m[input]++;
        n++;
    }
    cout<<fixed;
    cout.precision(4);
    for(auto i : m){
        cout<<i.first<<" ";
        double output=(i.second/(double)n)*100;
        cout<<output<<endl;
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}