#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
// vector<int> inOrder;
// vector<int> postOrder;
// vector<int> position;
int inOrder[100000+1];
int postOrder[100000+1];
int position[100000+1];
void Init(){
    cin>>n;
    // inOrder.resize(n);
    // postOrder.resize(n);
    // position.resize(n);
    // for(auto & i :inOrder)
    //     cin>>i;
    // for(auto & i :postOrder)
    //     cin>>i;
    // for(int i=0; i<n; i++)
    //     position[inOrder[i]]=i;
    
    for(int i=0; i<n; i++)
        cin>>inOrder[i];
    for(int i=0; i<n; i++)
        cin>>postOrder[i];
    for(int i=0; i<n; i++)
        position[inOrder[i]]=i;
}
void PrintPreOrder(int inLeft, int inRight,int postLeft, int postRight){
    if(inLeft>inRight|| postLeft>postRight) return;
    int root=postOrder[postRight];
    cout<<root<<" ";
    PrintPreOrder(inLeft, position[root]-1,postLeft,postLeft+(position[root]-inLeft)-1);
    PrintPreOrder(position[root]+1,inRight,postLeft+(position[root]-inLeft),postRight-1);
    
}
void Solve(){
    PrintPreOrder(0,n-1,0,n-1);
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