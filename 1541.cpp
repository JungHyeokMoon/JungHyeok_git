#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> stk;
int ret = 0;
void Input()
{
    cin >> str;
}
int pow_self(int a, int b){
    int temp=a;
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    while(1){
        if(b==1)break;
        a=a*temp;
        b--;
    }
    return a;
}
int Calcnum()
{
    int num = 0;
    int k=0;
    while (!stk.empty())
    {   
        int temp = (stk.top()-'0');
        stk.pop(); 
        num+=temp*pow_self(10,k++);
    }
    return num;
}
void Solve()
{
    int len = str.size();
    bool minus=false;
    for (int i = 0; i < len; i++)
    {
        if(str[i]=='-'){
            if(minus){
                ret-=Calcnum();
            }
            else{
                ret+=Calcnum();
            }
            minus=true;
        }
        else if (str[i]=='+'){
            if(minus){
                ret-=Calcnum();
            }
            else{
                ret+=Calcnum();
            }
        }
        else{
            stk.push(str[i]);
        }
    }


    //끝나고나서
    if(minus){
        ret-=Calcnum();
    }
    else{
        ret+=Calcnum();
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    Solve();
    cout<<ret<<"\n";
    return 0;
}