#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string str;
string Arr[3];
vector<string> sorted;
void Solve()
{
    cin >> str;
    int length = str.size();
    for (int i = 1; i < length - 1; i++)
    {
        for (int j = i+1; j < length ; j++)
        {   
            // cout<<i<<" "<<j <<endl;
            Arr[0] = str.substr(0, i);
            Arr[1] = str.substr(i, j-i);
            Arr[2] = str.substr(j, length); 
            //substr(idx, leng) idx부터 lengh만큼의 갯수 idx부터 leng 을 뽑아오는데 만약 스트링이 끝나면 스트링
            //끝나는데까지
            // cout<<Arr[0]<<" "<<Arr[1]<<" "<<Arr[2]<<endl;
            string temp = "";
            for (int k = 0; k < 3; k++)
            {
                reverse(Arr[k].begin(), Arr[k].end());
                // cout<<Arr[k]<<" ";
                temp += Arr[k];
            }
            // cout<<endl;
            sorted.push_back(temp);
        }
    }

    sort(sorted.begin(), sorted.end());
    cout << sorted[0];
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}