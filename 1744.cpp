#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<int> arr;
void Init()
{
    cin >> n;
    arr.resize(n);
    for (auto &i : arr)
        cin >> i;
}
void Solve()
{
    sort(arr.begin(), arr.end());
    long long ret = 0;
    priority_queue<int,vector<int>,greater<int>> minusNumber;
    priority_queue<int> plusNumber;
    int zeroCount = 0;
    int numberOne = 0;
    for (auto i : arr)
    {
        if (i < 0)
            minusNumber.push(i);
        else if (i == 0)
            zeroCount++;
        else if (i == 1)
            numberOne++;
        else
            plusNumber.push(i);
    }
    //1은 그냥 더해줘야함 곱해봤자 곱의 총합을 늘려주지 않기 때문에
    ret += numberOne;
    //양수들 2개씩뽑고 곱해서 더해줌
    while (plusNumber.size() >= 2)
    {
        int a = plusNumber.top();
        plusNumber.pop();
        int b = plusNumber.top();
        plusNumber.pop();

        ret += a * b;
    }
    if (plusNumber.size() == 1)
    {
        int a = plusNumber.top();
        plusNumber.pop();
        ret += a;
    }

    while (minusNumber.size() >= 2)
    {
        int a = minusNumber.top();
        minusNumber.pop();
        int b = minusNumber.top();
        minusNumber.pop();
        ret += a * b;
    }

    if (minusNumber.size() == 1)
    {
        if (zeroCount == 0)
        { 
            ret += minusNumber.top();
            minusNumber.pop();
        }
    }
    cout << ret << endl;
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