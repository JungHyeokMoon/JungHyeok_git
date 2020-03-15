#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<vector<int>> arr;
int ret=0;
void Input(){
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        arr[i].resize(5);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
        }
    }
    
}
void Solve(){
    int MAX=-987654321;
    for(int i=0; i<n; i++){//몇명 
        set<int> classmate; //중복을 제거하기위함 
        for(int j=0; j<5; j++){//6학년까지
            for(int k=0; k<n; k++){
                if(i==k) continue;//자기자신이랑같으면 continue

                if(arr[i][j]==arr[k][j]){ //같은반인적이있으면 set에 넣는데 set은 중복처리가 알아서 된다.
                    classmate.insert(k);
                }
            }
        }
        int cmp=classmate.size();
        if(MAX<cmp){
            MAX=cmp;
            ret=i;
        }
    }
    cout<<ret+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}