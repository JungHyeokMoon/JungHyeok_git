#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string A,B;
void Init(){
    cin>>A>>B;
}
void Solve(){
    string ret;
    int Alength=A.size();
    int Blength=B.size();
    for(int i=0; i<Alength; i++){
        ret.push_back(A[i]);
        if(B.back()==ret.back()){
            int retLength=ret.size();
            if(retLength>=Blength){
                string temp=ret.substr(retLength-Blength);
                if(temp==B){
                    for(int j=0; j<Blength; j++)
                        ret.pop_back();
                }
            }
        }
    }

    if(ret.empty())
        cout<<"FRULA"<<endl;
    else
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