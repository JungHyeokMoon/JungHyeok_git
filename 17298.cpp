#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<int> arr,ret;
void Input()
{
    cin >> n;
    arr.resize(n);
    ret.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void Solve()
{
    stack<int> stk;
    for(int i=n-1; i>=0 ;i--){
        while (!stk.empty() && arr[i]>=stk.top()) //스택을 배열 뒤에서부터훓는데 스택 내림차순정렬
        {
            stk.pop();
        }
        if(stk.empty()){
            ret[i]=-1;// 
        }
        else{
            ret[i]=stk.top();
        }
        stk.push(arr[i]);
    }
    for(int i=0; i<n; i++){
        cout<<ret[i]<<" ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}