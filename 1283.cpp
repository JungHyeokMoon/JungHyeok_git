#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
vector<string> Arr;
set<char> S;
void Init()
{
    cin >> N;
    cin.ignore(256, '\n');
    for (int i = 0; i < N; i++)
    {
        string temp;
        getline(cin, temp);
        Arr.push_back(temp);
    }
}
vector<string> Split(string str, char delimeter)
{
    vector<string> tempVector;
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == delimeter)
        {
            tempVector.push_back(temp);
            temp = "";
        }
        else
            temp.push_back(str[i]);
    }
    tempVector.push_back(temp);
    return tempVector;
}

bool SecondCondition(vector<string> splitedVector, int idx)
{
    string replaceStr;
    for (int i = 0; i < splitedVector.size(); i++)
    {
        for (int j = 0; j < splitedVector[i].size(); j++)
        {
            
            if (S.find(toupper(splitedVector[i][j])) == S.end())
            {
                
                S.insert(toupper(splitedVector[i][j]));
                replaceStr.push_back('[');
                replaceStr.push_back(splitedVector[i][j]);
                replaceStr.push_back(']');

                splitedVector[i].replace(j,1,replaceStr);
                for(auto k: splitedVector)
                    cout<<k<<" ";
                cout<<endl;
                return true;
            }
        }
    }
    return false;
}
bool FirstCondition(vector<char> &initalLetter, vector<string> & splitedVector)
{
    string replaceStr;
    for (int i=0; i<initalLetter.size(); i++)
    {
        if (S.find(toupper(initalLetter[i])) == S.end())
        { //없을경우 단축키등록
            S.insert(toupper(initalLetter[i]));
            replaceStr.push_back('[');
            replaceStr.push_back(initalLetter[i]);
            replaceStr.push_back(']');

            splitedVector[i].replace(0,1,replaceStr);
            for(auto j: splitedVector)
                cout<<j<<" ";
            cout<<endl;
            return true;
        }
    }

    return false;
}
void Solve()
{
    for (int i = 0; i < Arr.size(); i++)
    {
        vector<string> temp = Split(Arr[i], ' ');
        vector<char> initalLetter;
        for (int j = 0; j < temp.size(); j++)
            initalLetter.push_back(temp[j][0]); //단어의 첫글자 저장

        if (FirstCondition(initalLetter, temp))
            continue;
        if (SecondCondition(temp, i))
            continue;
        cout << Arr[i] << endl;
    }
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