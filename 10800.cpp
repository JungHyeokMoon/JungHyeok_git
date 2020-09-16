#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
class Data{
    public:
        int idx;
        int color;
        int size;
    
    Data(int idx,int color, int size){
        this->idx=idx;
        this->color=color;
        this->size=size;
    }
    
    bool operator <(const Data & D){
        if(this->size==D.size)
            return this->color<D.color;
        return this->size<D.size;
    }
};
int n;
vector<Data> v;
vector<int> ret;
vector<int> color;
vector<int> ballSize;
void Init(){
    cin>>n;
    ret.resize(n+1);
    color.resize(200000+1);
    ballSize.resize(200000+1);
    for(int i=0; i<n; i++){
        int color,size;
        cin>>color>>size;
        v.push_back({i+1,color,size});
    }   
    sort(v.begin(),v.end());
}
void Solve(){
    int sum=0;
    for(int i=0; i<n; i++){
        int curIdx=v[i].idx;
        int curColor=v[i].color;
        int curSize=v[i].size;

        color[curColor]+=curSize;
        ballSize[curSize]+=curSize;
        sum+=curSize;

        ret[curIdx]=sum-color[curColor]-ballSize[curSize]+curSize;
        if(i!=0 && curColor==v[i-1].color && curSize==v[i-1].size)
            ret[curIdx]=ret[v[i-1].idx];
        
    }
    for(int i=1; i<=n; i++)
        cout<<ret[i]<<endl;
    
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