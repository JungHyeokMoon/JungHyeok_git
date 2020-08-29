#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string fomula;
deque<long long> numbers;
deque<char> op;
int Compare(char op1, char op2)
{
    if (op1 == '+' || op1 == '-')
    {
        if (op2 == '*' || op2 == '/')
            return -1;
        else
            return 0;
    }
    else if (op1 == '*' || op1 == '/')
    {
        if (op2 == '-' || op2 == '+')
            return 1;
        else
            return 0;
    }
}
void Init()
{
    cin >> fomula;
    int length = fomula.size();
    string temp;
    for (int i = 0; i < length; i++)
    {
        if (fomula[i] == '+' || fomula[i] == '/' || fomula[i] == '*')
        {
            numbers.push_back(stoll(temp));
            temp = "";
            op.push_back(fomula[i]);
        }
        else if (fomula[i] == '-')
        {
            if (i == 0)
            {
                temp.push_back(fomula[i]);
            }
            else
            {
                numbers.push_back(stoll(temp));
                temp = "";
                op.push_back(fomula[i]);
            }
        }
        else
            temp.push_back(fomula[i]);
    }
    numbers.push_back(stoll(temp));
}
long long Calc(long long number1, long long number2, char op){
    if(op=='+')
        return number1+number2;
    else if(op=='-')
        return number1-number2;
    else if(op=='*')
        return number1*number2;
    else 
        return number1/number2;
}
void Solve()
{
    while (numbers.size() != 1)
    {
        char op1 = op.front();
        char op2 = op.back();
        if (Compare(op1, op2) == 1) //op1이 우선순위 더 클때
        {
            long long number1=numbers.front();
            numbers.pop_front();
            long long number2=numbers.front();
            numbers.pop_front();

            long long result=Calc(number1,number2,op1);

        
            numbers.push_front(result);
            op.pop_front();
        }
        else if (Compare(op1, op2) == 0) //우선순위 같을때
        {
            long long number1=numbers[0];
            long long number2=numbers[1];

            int numbersLength=numbers.size();

            long long number3=numbers[numbersLength-2];
            long long number4=numbers[numbersLength-1];

            long long result1=Calc(number1,number2,op1);
            long long result2=Calc(number3,number4,op2);

            if(result1>=result2){
                numbers.pop_front();
                numbers.pop_front();
                numbers.push_front(result1);
                op.pop_front();
            }
            else{
                numbers.pop_back();
                numbers.pop_back();
                numbers.push_back(result2);
                op.pop_back();
            }
        }
        else //우선순위 op1이 작을때
        {
            int numbersLength=numbers.size();
            long long number1=numbers[numbersLength-2];
            long long number2=numbers[numbersLength-1];
            numbers.pop_back();
            numbers.pop_back();

            long long result=Calc(number1,number2,op2);
            numbers.push_back(result);
            op.pop_back();
        }
    }
    cout<<numbers[0]<<endl;
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