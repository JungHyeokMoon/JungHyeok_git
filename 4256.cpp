#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int t;
int n;
vector<int> preorder;
vector<int> inorder;
// vector<int> Slice(const vector<int> a,int s, int e){
//     return vector<int>(a.begin()+s,a.begin()+e);
//     //[0,e)
// }
// void PostOrder(const vector<int> pre, const vector<int> in){
//     if(pre.empty()){
//         return ;
//     }
//     int N=pre.size();
//     int root=pre[0];

//     int L=find(in.begin(),in.end(),root)-in.begin();
//     int R=N-L-1;// 오른쪽의갯수는 N-왼쪽트리갯수 - 루트갯수
//     PostOrder(Slice(pre,1,L+1),Slice(in,0,L));//pre의 루트띄어내고 [1,L+1), in의 [0,L]
//     PostOrder(Slice(pre,L+1,N),Slice(in,L+1,N)); //pre [L+1,N), in의 [L+1,N)
    
//     cout<<root<<" ";
// }
//전위, 중위가 주어졌을때 후위순회는
void PostOrder(int ps,int pe,int is,int ie){
    if(ps>=pe){
        return ;
    }
    int root=preorder[ps];
    int idx=0;
    for(int i=is; idx<ie; i++){
        if(inorder[i]==root){
            break;
        }
        idx++; //idx는 inorder의 시작점부터 몇번쨰인지를 찾아줘야함
    }

    PostOrder(ps+1,ps+idx+1,is,is+idx);
    PostOrder(ps+idx+1,pe,is+idx+1,ie);

    cout<<root<<" ";
    
}
void Solve(){
    cin>>t;
    while(t--){
        cin>>n;
        preorder.resize(n);
        inorder.resize(n);
        for(int i=0; i<n; i++){
            cin>>preorder[i];
        }
        for(int i=0; i<n; i++){
            cin>>inorder[i];
        }
        
        
        PostOrder(0,n,0,n);
        cout<<endl;
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

