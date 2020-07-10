// #include <bits/stdc++.h>
// using namespace std;

// int n,m;
// vector<int>ret;
// int arr[7];
// void n_m(int cnt){
//     if(cnt==m){
//         for(auto i : ret) cout<<i<<" ";
//         cout<<"\n";
//         return ;
//     }
//     for(int i=0; i<n ; i++){
//         ret.push_back(arr[i]);
//         n_m(cnt+1);
//         ret.pop_back();
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>n>>m;
//     for(int i=0; i<n; i++)
//         cin>>arr[i];

//     sort(arr,arr+n);
//     n_m(0);

//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> input;
vector<int> ret;
int n, m;
void Init()
{
    cin >> n >> m;
    input.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
}
void Recursion()
{
    if (ret.size() == m)
    {
        for (auto i : ret)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        ret.push_back(input[i]);
        Recursion();
        ret.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    Recursion();
    return 0;
}
