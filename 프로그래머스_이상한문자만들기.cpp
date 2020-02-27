#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
string answer = "";
string temp = "";

void plusstring(string temp)
{
    for (int j = 0; j < temp.size(); j++)
    {
        //TODO:answer에 붙여넣기
        if (j % 2 == 0)
        {
            if ('A' <= temp[j] && temp[j] <= 'Z')
            {
                answer.push_back(temp[j]);
            }
            else if ('a' <= temp[j] && temp[j] <= 'z')
            {
                answer.push_back(temp[j] - 'a' + 'A');
            }
        }
        else
        {
            if ('A' <= temp[j] && temp[j] <= 'Z')
            {
                answer.push_back(temp[j] - 'A' + 'a');
            }
            else if ('a' <= temp[j] && temp[j] <= 'z')
            {
                answer.push_back(temp[j]);
            }
        }
    }
}
string solution(string s)
{
    int length = s.size();
    bool flag = false;

    for (int i = 0; i < length; i++)
    {
        if (s[i] == ' ')
        {
            // cout << temp << endl;
            plusstring(temp);
            answer.push_back(s[i]);
            temp = "";
        }
        else
        {
            temp.push_back(s[i]);
        } //문자면 temp에넣는다.
    }
    plusstring(temp);

    return answer;
}