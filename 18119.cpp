#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
vector<int> word;
int bitmap=0x3ffffff; //26개 다 알고있으니깐
void Init()
{
    cin >> n>>m;
    word.resize(n,0);
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(auto j: temp){
            word[i]=word[i]|( 1<<(j-'a')); //단어마다 알고있는 것들 비트마스크에체크
        }
    }

}
void Solve()
{
    for (int i = 0; i < m; i++)
    {
        char cmd, alphabet;
        cin >> cmd >> alphabet;
        if(alphabet!='a')
        if (cmd == '1') //잊는것
            bitmap = (bitmap & ~(1 << (alphabet-'a')));
        else //기억해냄
            bitmap = (bitmap | (1 << (alphabet-'a')));
        
        int ret = n;
        for (int i = 0; i < n; i++)
        {
            if((word[i]& bitmap)!=word[i])
                ret--;
        }
        cout<<ret<<endl;
    }
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