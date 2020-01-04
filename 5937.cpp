#include <bits/stdc++.h>
using namespace std;


int n;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin>>n;

    for(int i=0; i<n; i++){
        string A;
        cin>>A;

        list<char> L;
        list<char>::iterator p=L.begin();
        int len=A.size();

        for(int j=0; j<len ; j++){
            if(A[j]=='<'){
                if(p!=L.begin()){
                    p--;
                }//커서앞으로이동
            }
            else if(A[j]=='>'){
                if(p!=L.end()){
                    p++;
                }
            }//
            else if(A[j]=='-'){
                if(p!=L.begin()){
                    p--;
                    p=L.erase(p);
                }//커서앞으로 당기고 삭제
            }
            else{
                L.insert(p,A[j]);
            }
        }

        for(auto i : L)cout<<i;
        cout<<"\n";
    }

    return 0;
}