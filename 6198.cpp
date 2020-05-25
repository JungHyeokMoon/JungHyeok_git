#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> building;
int n;
long long ret;
void Input()
{
    cin >> n;
    building.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> building[i];
    }
}
//문제의 설명은 각빌딩이 가려지지않고 몇개를 볼수있냐
//역으로 생각해서 각빌딩이 몇개의 건물에 보여지냐 이렇게풀이
void Solve()
{

    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && stk.top() <= building[i])
            stk.pop();                //스택을 순 감소 형태로 만들어줘야함
        ret += (long long)stk.size(); //스택의 사이즈는 자기를 볼수있는 빌딩의 갯수이다. 순감소형태로 스택이 들어있으니깐
        stk.push(building[i]);
    }

    cout << ret << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
