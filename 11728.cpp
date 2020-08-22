// #include <bits/stdc++.h>
// using namespace std;

// int n,m;

// void merge(int *A, int *B){
//     int *C=new int[n+m];

//     int i=0,j=0,k=0;
//     int flag=0;
//     while(1){
//         if(i==n||j==m){
//             if(i==n){
//                 flag=1; //A가먼저끝난경우
//             }else{
//                 flag=2; //B가먼저끝난경우
//             }
//             break;
//         }

//         if(A[i]>=B[j]){
//             C[k++]=B[j++];
//         }
//         else{
//             C[k++]=A[i++];
//         }
//     }
//     if(flag==1){
//         for(; j<m; j++){
//             C[k++]=B[j];
//         }
//     }
//     else{
//         for( ; i<n ; i++){
//             C[k++]=A[i];
//         }
//     }

//     for(int l=0; l<n+m; l++){
//         cout<<C[l]<<" ";
//     }
//     cout<<"\n";
//     return ;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin>>n>>m;
//     int *a,*b;
//     a=new int[n];
//     b=new int[m];
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     for(int i=0; i<m; i++){
//         cin>>b[i];
//     }
//     sort(a,a+n);
//     sort(b,b+m);

//     merge(a,b);
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
vector<int> A,B;
void Init(){
    cin>>n>>m;
    A.resize(n);
    B.resize(m);

    for(int i=0; i<n; i++)
        cin>>A[i];

    for(int i=0; i<m; i++)
        cin>>B[i];
}
void Solve(){
    vector<int> C(n+m);

    int k=0, i=0, j=0; //배열 C의 인덱스, A의 인덱스, B의 인덱스
    while(i!=n && j!=m){
        if(A[i]>=B[j])
            C[k++]=B[j++];
        else
            C[k++]=A[i++];
    }

    while(i<n){ //남았을경우
        C[k++]=A[i++];
    }
    while(j<m){
        C[k++]=B[j++];
    }

    for(auto i :C)
        cout<<i<<" ";
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