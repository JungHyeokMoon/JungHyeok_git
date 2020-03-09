#include <bits/stdc++.h>
using namespace std;
int n;
int arr[126][126];
int dist[126];
#define endl "\n"
#define MAX 987654321
void Init(){
    for(int i=0; i<n; i++){
        fill(arr[i],arr[i]+n,0);
    }
    // for(int i=0; i<n; i++){
    //     fill(dist[i],dist[i]+n,987654321);
    // }
    fill(dist,dist+n,MAX);
}
void Problem(int i){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({arr[0][0],0}); //도둑루피, vertex
    dist[0]=arr[0][0];
    while(!pq.empty()){
        int hc=pq.top().first;
        int hv=pq.top().second;
        cout<<i+1<<" : "<<hc<<", "<<hv<<endl;
        pq.pop();
        if(dist[hv]<hc)continue;  //이렇게되면 뒤에 더 코드가 진행되도 갱신될 여지가없음

        for(int i=0; i<n ; i++){
            // if(hc==i)continue;
            int nv=i;
            int nc=hc+arr[hv][i];
            if(nc<dist[nv]){
                dist[nv]=nc;
                pq.push({nc,nv});
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     cout<<dist[i]<<" ";
    // }
    //test
    //test
    cout<<"Problem "<<i<<": "<<dist[n-1]<<endl;
}
void Solve(){
    int i=1;
    while(1){
        cin>>n;
        if(!n){
            break;
        }
        Init();
        
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cin>>arr[j][k];
            }
        }
        
        Problem(i);
        i++;
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}