#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<string> v;
map<char, int> m;

int cnt = 0;
void Input()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}
void Solve()
{ //비슷한단어는 같은구성을 갖거나, 한문자를 더하거나 빼거나 ,하나의문자를 다른문자로 바꾸어 나머지 한단어와 같은구성을 갖게되는경우
    int firstleng = v[0].size();
    for (int i = 0; i < firstleng; i++)
    {
        m[v[0][i]]++;
        // upper[v[0][i]-'A']++;
    }
    map<char, int>::iterator it;
    for (int i = 1; i < n; i++)
    {
        int templeng = v[i].size();
        if (abs(firstleng - templeng) >= 2)
        {
            continue;
        } //애초에 길이가 2차이나면 비교할필요도없음
        map<char, int> temp;
        for (int j = 0; j < templeng; j++)
        {
            temp[v[i][j]]++;
        }
        int diff=0;
        for(char ch='A'; ch<='Z'; ch++){
            diff+=abs(m[ch]-temp[ch]);
        }//순서가 다를수 있기 때문에 'A'부터 'Z'까지돌아야함 반복문유의
        if(diff<=2){
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}