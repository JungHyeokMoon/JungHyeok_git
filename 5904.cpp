#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
long long arr[50];
char Recursion(int n) //n번째 문자를 return
{
    if (n == 1)
        return 'm';
    else if (n == 2 || n == 3)
        return 'o';
    int idx = 0;
    while (arr[idx] < n)
        idx++;
    if (arr[idx] == n)
        return 'o';
    else if (n - arr[idx - 1] == 1)
        return 'm';
    else if (n - arr[idx - 1] <= idx + 3)
        return 'o';
    else
        return Recursion(n - arr[idx - 1] - (idx + 3));
}
void Solve()
{
    cin >> N;
    arr[0] = 3;
    for (int i = 1; i <= 40; i++)
    {
        arr[i] = arr[i - 1] * 2 + i + 3;
    }
    cout << Recursion(N);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}