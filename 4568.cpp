#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void Solve()
{
    string input;
    int cnt = 0;
    int capacity;
    while (cin>>capacity)
    {
        if (capacity == 0)
            break;
        cin>>input;
        cout << "Simulation " << ++cnt << endl;
        int size = 0;
        list<char> cache;
        vector<bool> visited(26, false);
        for (auto i : input)
        {
            if (i == '!')
            {
                for (auto i : cache)
                    cout << i;
                cout << endl;
                continue;
            }

            if (visited[i - 'A'] == false)
            {
                if (size < capacity)
                {
                    // cout << "here1: " << i << endl;
                    size++;
                    cache.push_back(i);
                    visited[i - 'A'] = true;
                }
                else
                {
                    // cout << "here2: " << i << endl;
                    visited[cache.front() - 'A'] = false;
                    cache.pop_front();

                    cache.push_back(i);
                    visited[i - 'A'] = true;
                }
            }
            else
            {
                // cout << "here3: " << i << endl;
                for (auto it = cache.begin(); it != cache.end(); it++)
                {
                    if (*it == i)
                    {
                        cache.erase(it);
                        break;
                    }
                }
                cache.push_back(i);
            }
            
        }
        cache.clear();
        visited.clear();
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