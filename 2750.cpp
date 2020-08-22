#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<int> A;
void Init(){
    cin>>n;
    A.resize(n);
    for(int i=0; i<n; i++)
        cin>>A[i];
}
void BubbleSort(){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-1-i; j++)
            if(A[j]>A[j+1])
                swap(A[j],A[j+1]);
}
void Output(){
    for(auto i : A)
        cout<<i<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    BubbleSort();
    Output();
    return 0;
}