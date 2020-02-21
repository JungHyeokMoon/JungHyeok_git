#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<pair<pair<string, int>, long long>> v;
string inputArr[3];
long long ret = 0;
void Input()
{
    v.push_back({make_pair(make_pair("black", 0), 1)});
    v.push_back({make_pair(make_pair("brown", 1), 10)});
    v.push_back({make_pair(make_pair("red", 2), 100)});
    v.push_back({make_pair(make_pair("orange", 3), 1000)});
    v.push_back({make_pair(make_pair("yellow", 4), 10000)});
    v.push_back({make_pair(make_pair("green", 5), 100000)});
    v.push_back({make_pair(make_pair("blue", 6), 1000000)});
    v.push_back({make_pair(make_pair("violet", 7), 10000000)});
    v.push_back({make_pair(make_pair("grey", 8), 100000000)});
    v.push_back({make_pair(make_pair("white", 9), 1000000000)});

    // cout<<v[0].first.first<<endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> inputArr[i];
    }
}
void Solve()
{
    // cout<<"before : "<<ret<<endl;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (inputArr[j] == v[i].first.first)
            {
                // cout<<"color : "<<v[i].first.first<<" value : "<<v[i].first.second<<endl;
                if (j == 0)
                {

                    ret += (v[i].first.second) * 10;
                    // cout<<"ret : "<<ret<<endl;
                }
                else if (j == 1)
                {
                    ret += v[i].first.second;
                }
                else
                {
                    // string temp = v[i].second;
                    // cout<<"temp : "<<temp<<" Number: "<<temp+'0'<<endl;

                    // temp.erase(temp.begin());
                    // if (ret != "0")
                    // {
                    //     ret += temp;
                    // }
                    long long temp = v[i].second;
                    // cout<<temp<<endl;
                    ret *= temp;
                }
            }
        }
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
