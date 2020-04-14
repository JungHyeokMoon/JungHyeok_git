// #include <bits/stdc++.h>	
// #define endl "\n"	
// using namespace std;
// int n;
// bool sosu[10000000+1]={false};
// string temp="";
// // vector<int> ret;
// void Find_sosu(){
//     if(temp.size()==n){
//         cout<<temp<<endl;
//         return ;
//     }

//     for(int i=0; i<=9; i++){
//         if(temp.size()==0 && i==0)continue;
//         temp.push_back(char(i+'0'));
//         if(sosu[stoi(temp)]==true){
//             temp.pop_back();
//             continue;
//         }
//         Find_sosu();
//         temp.pop_back();
//     }
// }
// void eratos(){
//     sosu[0]=true;
//     sosu[1]=true;
//     for(int i=1; i*i<=10000000; i++){
//         if(!sosu[i]){
//             for(int j=2*i; j<=10000000; j+=i){
//                 sosu[j]=true;
//             }
//         }
//     }
// }
// void Solve(){
//     cin>>n;
//     eratos();
//     Find_sosu();
//     // cout<<temp<<endl;
//     // temp+=char(3+'0');
//     // cout<<temp<<endl;
// }
// int main(){	
//     ios_base::sync_with_stdio(0);	
//     cin.tie(0);	
//     cout.tie(0);
//     Solve();
//     return 0;
// }
// //메모리초과 받은코드 4mb제한이있었다.


#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;
int n;

string Arr[4]={"2","3","5","7"};
void Find_sosu(string str){
    if(str.size()==n){
        cout<<str<<endl;
        return ;
    }

    for(int i=0; i<=9; i++){
        str.push_back(char(i+'0'));
        int num=stoi(str);
        bool flag=false;
        for(int j=2; j*j<=num; j++){
            if(num%j==0){
                str.pop_back();
                flag=true;
                break;
            }
        }
        if(flag){
            continue;
        }
        else{
            Find_sosu(str);
            str.pop_back();
        }
    }
}

void Solve(){
    cin>>n;
    for(int i=0; i<4; i++){
        Find_sosu(Arr[i]);
    }
}
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Solve();
    return 0;
}
//메모리초과 받은코드 4mb제한이있었다.