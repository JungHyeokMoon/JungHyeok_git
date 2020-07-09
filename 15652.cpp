// #include <bits/stdc++.h>
// using namespace std;

// int n,m;
// vector<int> ret;
// void n_m(int start,int cnt){

//     if(cnt==m){
//         for(auto i :ret )cout<<i<<" ";
//         cout<<"\n";
//         return ;
//     }

//     for(int i=start; i<=n; i++){
//         ret.push_back(i);
//         n_m(i,cnt+1);
//         ret.pop_back();
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>n>>m;
//     n_m(1,0);
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
vector<int> arr;
void Recursion(int k)
{
    if (arr.size() == m)
    {
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    for (int i = k; i <= n; i++)
    {
        arr.push_back(i);
        Recursion(i);
        arr.pop_back();
    }
}
void Solve()
{
    cin >> n >> m;
    Recursion(1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}