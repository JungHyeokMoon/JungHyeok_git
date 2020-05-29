// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// void Solve(){
//     int idx=1;
//     while(1){
//         string input;
//         cin>>input;
//         if(input[0]=='-'){
//             break;
//         }
//         stack<char> stk;

//         int cnt=0;
//         int length=input.size();
//         for(int i=0; i<length; i++){
//             if(stk.empty() && input[i]=='}'){
//                 stk.push('{');
//                 cnt++;
//                 // if(idx==4)cout<<"cnt : "<<cnt<<endl;
//             }
//             else if(input[i]=='}'){
//                 stk.pop();
//             }
//             else if(input[i]=='{'){
//                 // if(stk.empty()){
//                 //     for(int i=0; i<cnt; i++){
//                 //         stk.push(input[i]);
//                 //     }
//                 // }
//                 stk.push(input[i]);
//             }

//         }

//         while(!stk.empty()){
//             stk.pop();
//             cnt++;
//             // if(idx==4)cout<<"cnt : "<<cnt<<" , "<<stk.size()<<endl;
//             stk.pop();
//         }

//         cout<<idx<<". "<<cnt<<endl;
//         idx++;
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);
//     cout.tie(NULL);
//     Solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int Countcal(string str)
{
    stack<char> stk;
    int ret = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char blanket = str[i];
        if (blanket == '{')
        {
            stk.push(blanket);
        }
        else
        {
            if (stk.empty())
            {
                ret++;
                stk.push('{');
            }
            else
            {
                stk.pop();
            }
        }
    }
    return stk.size() == 0 ? ret : ret + stk.size() / 2;
}
void Solve()
{
    int idx = 0;
    while (++idx)
    {
        string str;
        cin >> str;
        if (str.find('-') != string::npos)
        {
            // cout << str << endl;
            break;
        }
        cout << idx << ". " << Countcal(str) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
