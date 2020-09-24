#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<vector<int>> MAP;
int ret=0;
int FindSecountNumber(int i, int j){
	vector<int> temp;
	for(int y=i; y<i+2; y++){
		for(int x=j; x<j+2; x++){
			temp.push_back(MAP[y][x]);
		}
	}
	sort(temp.begin(), temp.end());
	return temp[2];
}
void Init(){
	cin>>n;
	MAP.resize(n,vector<int>(n));
	for(auto & i :MAP)
		for(auto & j : i)
			cin>>j;
}
void Recursive(int n){
	if(n==2){
		ret=FindSecountNumber(0,0);
		return ;
	}

	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			MAP[i][j]=FindSecountNumber(i*2,j*2);
		}
	}
	Recursive(n/2);
}
void Solve(){
	Recursive(n);
	cout<<ret<<endl;
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