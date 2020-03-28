#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int t;
int n;
void Solve(){
    cin>>t;
    while (t--)
    {
        cin>>n;
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i].first>>v[i].second;
        }
        
        sort(v.begin(), v.end()); //정렬해서
        
        
        int cnt=1;
        int temp=v[0].second;//첫번째사람은 무조건 뽑힘 서류가1등이라서 면접점수 저장
        for(int i=1; i<n; i++){
            if(temp>v[i].second){//첫번째서류사람보다 더 높은등수의 면접점수를 가지고있다면 초기화해주고 카운트증가
                temp=v[i].second;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    

}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}