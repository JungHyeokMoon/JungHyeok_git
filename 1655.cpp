#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
priority_queue<int> maxHeap;
priority_queue<int> minHeap;
void Solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        if(maxHeap.size()==minHeap.size())
            maxHeap.push(num);
        else
            minHeap.push(-num);

        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > -minHeap.top()){
            int a=maxHeap.top();
            int b=-minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(b);
            minHeap.push(-a);
        }
        cout<<maxHeap.top()<<endl;
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