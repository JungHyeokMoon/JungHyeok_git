// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n,m;
// vector<bool> visited;
// vector<int> arr;
// vector<int> Combi;
// set<string> s;
// void Input(){
//     cin>>n>>m;
//     visited.resize(n,false);
//     arr.resize(n);
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     sort(arr.begin(),arr.end());
// }
// void Make_Combi(int depth,int idx){
//     if(depth==m){
//         string temp="";
//         int length=Combi.size();
//         for(int i=0; i<length; i++){
//             temp+=(Combi[i]+'0');
//             if(i!=length-1){
//                 temp.push_back(' ');
//             }
//         }
//         if(s.find(temp)==s.end()){
//             s.insert(temp);
//             for(int i=0; i<length; i++){
//                 cout<<Combi[i]<<" ";
//             }
//             cout<<endl;
//         }
//         return ;
//     }

//     for(int i=idx; i<n; i++){
//         if(!visited[i]){
//             visited[i]=true;
//             Combi.push_back(arr[i]);
//             Make_Combi(depth+1,i+1);
//             Combi.pop_back();
//             visited[i]=false;
//         }
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Input();
//     Make_Combi(0,0);
//     return 0;
// }

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n, m;
// vector<int> arr;
// vector<bool> visited;
// vector<int> ret;
// set<string> s;
// void Init()
// {
//     cin >> n >> m;
//     arr.resize(n);
//     visited.resize(n, false);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     sort(arr.begin(), arr.end());
//     visited.resize(10000, false);
// }
// void Recursion(int k)
// {
//     if (ret.size() == m)
//     {
//         string str = "";
//         for (int i = 0; i < ret.size(); i++)
//         {
//             str.push_back(ret[i] + '0');
//             if (i != ret.size() - 1)
//             {
//                 str.push_back(' ');
//             }
//         }
//         if (s.find(str) == s.end())
//         {
//             s.insert(str);
//             for (int i = 0; i < ret.size(); i++)
//             {
//                 cout << ret[i] << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }
//     for (int i = k; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             visited[i] = true;
//             ret.push_back(arr[i]);
//             Recursion(i + 1);
//             ret.pop_back();
//             visited[i] = false;
//         }
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Init();
//     Recursion(0);
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
set<vector<int>> S;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> combi(n, 1);
    for (int i = 0; i < m; i++)
        combi[i] = 0;

    sort(v.begin(), v.end());
    do
    {
        vector<int> ret;
        for (int i = 0; i < combi.size(); i++)
        {
            if (combi[i] == 0)
            {
                ret.push_back(v[i]);
            }
        }

        if (S.find(ret) == S.end())
        {
            for (int i = 0; i < ret.size(); i++)
            {
                cout << ret[i] << " ";
            }
            S.insert(ret);
            cout << endl;
        }

    } while (next_permutation(combi.begin(), combi.end()));
    return 0;
}
