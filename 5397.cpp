#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<string> Arr;
void Input()
{
    cin >> n;
    Arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
}
void Solve()
{
    for (int i = 0; i < n; i++)
    {
        list<char> L;
        list<char>::iterator it = L.begin();
        string tempStr = Arr[i];
        for (int j = 0; j < tempStr.size(); j++)
        {
            char tempC = tempStr[j];
            if (tempC == '<')
            {

                if (it != L.begin())
                {
                    it--;
                }
            }
            else if (tempC == '>')
            {
                if (it != L.end())
                {
                    it++;
                }
            }
            else if (tempC == '-')
            {
                if (it != L.begin())
                {
                    it--;
                    it = L.erase(it);
                }
            }
            else
            {
                L.insert(it, tempC);
            }
        }
        for (auto i : L)
        {
            cout << i;
        }
        cout << endl;
    }
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