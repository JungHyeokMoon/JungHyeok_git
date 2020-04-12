#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string input;
map<char, int> m;
int Upper[26] = {0};
void Solve()
{
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        m[input[i]]++;
    }
    
    vector<pair<char,int>> odd;
    for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        if ((it->second) % 2 != 0)
        {
            odd.push_back({it->first,it->second});
            if (odd.size()>=2)
            {
                cout << "I'm Sorry Hansoo" << endl;
                return;
            }
            // cout<<One<<endl;
        }
        Upper[(it->first) - 'A'] = it->second;
    }
    string answer = "";
    if(odd.size()==0){
        for (int i = 0; i < 26; i++)
        {
            int number = Upper[i];
            if (number != 0)
            {
                for(int k=0; k<(number/2); k++){
                    answer.push_back(char(i+'A'));
                }
            }
        }
        int length=answer.size();
        for(int i=length-1; i>=0; i--){
            answer.push_back(answer[i]);
        }
    }
    else{
        char A=odd[0].first;
        char num=odd[0].second;
        for (int i = 0; i < 26; i++)
        {
            int number = Upper[i];
            if (number != 0)
            {
                for(int k=0; k<(number/2); k++){
                    answer.push_back(char(i+'A'));
                }
            }
        }
        answer.push_back(A);
        int length=answer.size();
        for(int i=length-2; i>=0 ;i--){
            answer.push_back(answer[i]);
        }
    }
    
    
    cout << answer << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}