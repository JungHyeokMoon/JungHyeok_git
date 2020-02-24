#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    int length = commands.size();
    vector<int> answer;
    for (int i = 0; i < length; i++)
    {
        vector<int> temp;
        int start = commands[i][0] - 1;
        int end = commands[i][1] - 1;
        int k = commands[i][2];
        for (int j = start; j <= end; j++)
        {
            temp.push_back(array[j]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);
    }

    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges