#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k;
vector<int> arr;
vector<int> multitab;
int ret = 0;
void Input()
{
    cin >> n >> k;
    arr.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
}
int Find(int key)
{
    for (int i = 0; i < multitab.size(); i++)
    {
        if (multitab[i] == key)
        {
            return i;
        }
    }
    return -1;
}
void Output(int idx)
{
    cout << "idx " << idx << " : ";
    for (int i = 0; i < multitab.size(); i++)
    {
        cout << multitab[i] << " ";
    }
    cout << endl;
}
int Find2(int key, int s, int e)
{
    for (int i = s; i < e; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}
void Solve()
{
    for (int i = 0; i < k; i++)
    {
        if (Find(arr[i]) != -1)
        {
            // Output(i);
            // cout<<"here"<<endl;
            continue;
        }
        if (multitab.size() != n)
        {
            multitab.push_back(arr[i]);
        }
        else
        {
            ret++;
            int lastindex = -1;
            int chageindex = 0;
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                int temp = Find2(multitab[j], i+1, k);
                if (temp == -1)
                {
                    multitab.erase(multitab.begin() + j);
                    multitab.insert(multitab.begin() + j, arr[i]);
                    flag = true;
                    break;
                }
                else
                {
                    if (lastindex < temp)
                    {
                        lastindex = temp;
                        chageindex = j;
                    }
                }
            }
            if (!flag)
            {
                multitab.erase(multitab.begin() + chageindex);
                multitab.insert(multitab.begin() + chageindex, arr[i]);
            }
            
        }
        // Output(i);
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