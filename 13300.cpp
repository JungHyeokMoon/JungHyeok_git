#include <bits/stdc++.h>
using namespace std;

int n,k;

int student[6][2];
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin>>n>>k;

    if(k==1){
        cout<<n<<"\n";
        return 0;
    }

    for(int i=0; i<n; i++){
        int sex,year;
        cin>>sex>>year;
        student[year-1][sex]++;
    }
    int ret=0;

    for(int i=0; i<6; i++){
        for(int j=0; j<2; j++){
            if(student[i][j]!=0){
                if(student[i][j]%k==0){
                    ret+=(student[i][j]/k);
                }
                else{
                    ret+=(student[i][j]/k)+1;
                }
            }
        }
    }

    cout<<ret<<"\n";
    return 0;
}