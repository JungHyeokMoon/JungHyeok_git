#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

stack<int> stk;
vector<int> numberOfDoll;
void CountDoll(vector<vector<int>> &board)
{
    numberOfDoll.resize(board[0].size());
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != 0)
            {
                numberOfDoll[j]++;
            }
        }
    }
}
int Solve(int N, vector<vector<int>> &board, vector<int> &moves)
{
    int ret = 0;
    for (int i = 0; i < moves.size(); i++)
    {
        if (numberOfDoll[moves[i] - 1] == 0)
            continue;
        else
        {
            int item = board[N - numberOfDoll[moves[i] - 1]][moves[i] - 1];
            numberOfDoll[moves[i] - 1]--;
            if (stk.empty())
            {
                stk.push(item);
            }
            else
            {
                if (stk.top() == item)
                {
                    cout << item << endl;
                    stk.pop();
                    ret++;
                }
                else
                {
                    stk.push(item);
                }
            }
        }
    }
    return ret * 2;
}
int solution(vector<vector<int>> board, vector<int> moves)
{
    CountDoll(board);
    int answer = Solve(board.size(), board, moves);
    return answer;
}