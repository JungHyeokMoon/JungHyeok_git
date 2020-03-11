#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
queue<int> q;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0 ; i<n ; i++){
        string temp;
        cin>>temp;
        if(temp=="pop"){
            if(q.empty()){
                cout<<-1<<endl;
            }
            else{
                cout<<q.front()<<endl;
                q.pop();
            }
        }
        else if(temp=="size"){
            cout<<q.size()<<endl;
        }
        else if(temp=="empty"){
            if(q.empty()){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else if(temp=="front"){
            if(q.empty()){
                cout<<-1<<endl;
            }
            else{
                cout<<q.front()<<endl;
            }   
        }
        else if(temp=="back"){
            if(q.empty()){
                cout<<-1<<endl;
            }
            else{
                cout<<q.back()<<endl;
            }
        }
        else{
            int num;
            cin>>num;
            q.push(num);
        }
    }
}