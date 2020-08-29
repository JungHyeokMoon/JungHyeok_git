#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string Input;
void Solve(){
   cin>>Input;
   regex reg ("(10(0+)(1+)|01)+");
   if(regex_match(Input,reg))
      cout<<"SUBMARINE"<<endl;
   else
      cout<<"NOISE"<<endl;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   Solve();
   return 0;
}