#include <bits/stdc++.h>
using namespace std;

long long solution(string expression)
{
    long long answer = 0;
    vector<long long> numbers;
    vector<char> location;
    set<char> temp;
    
    string str;
    for(auto i : expression){
        if('0'<=i && i<='9')
            str.push_back(i);
        else{
            numbers.push_back(stoll(str));
            location.push_back(i);
            str="";
            temp.insert(i);
        }

    }
    numbers.push_back(stoll(str));
    vector<char> op(temp.begin(), temp.end());
    
    do{
        vector<long long> tempNumbers=numbers;
        vector<char> tempLocation=location;
        
        for(int i=0; i<op.size(); i++){
            for(int j=0; j<tempLocation.size(); j++){
                if(op[i]==tempLocation[j]){

                    if(tempLocation[j]=='+'){
                        tempNumbers[j]=tempNumbers[j]+tempNumbers[j+1];
                    }
                    else if(tempLocation[j]=='-'){
                        tempNumbers[j]=tempNumbers[j]-tempNumbers[j+1];
                    }else{
                        tempNumbers[j]=tempNumbers[j]*tempNumbers[j+1];
                    }

                    tempNumbers.erase(tempNumbers.begin()+j+1);
                    tempLocation.erase(tempLocation.begin()+j);
                    j--;
                }
            }
        }
        answer=max(answer,abs(tempNumbers[0]));
    }while(next_permutation(op.begin(),op.end()));
    return answer;
}

int main()
{
    cout <<"Answer: " <<solution("100-200*300-500+20") << endl;
    cout <<"Answer: " <<solution("50*6-3*2") << endl;
    // cout <<"Answer: " <<solution("-200+50*6-3*2") << endl;
    // cout <<"Answer: " <<solution("-100-200-300+300") << endl;
    return 0;
}
//계산할때마다 갈아끼워넣어줘야하는듯함.


// long long solution(string expression)
// {
//     long long answer = 0;
//     char operand[3] = {'*', '+', '-'};
//     do
//     {
//         for (auto ch : operand)
//             cout << ch << " ";
//         cout << ": ";

//         string copyExpression = expression;
//         cout << "original: " << copyExpression << endl;
//         for (auto ch : operand)
//         {
//             if (ch == '+')
//             {
//                 size_t start_pos = 0;
//                 while ((start_pos = copyExpression.find(ch, start_pos)) != string::npos)
//                 {
//                     string left;
//                     for (int i = start_pos - 1; i >= 0; i--)
//                     {
//                             else
//                                 break;
//                         }
//                         else
//                             left.push_back(pushC);
//                     }
//                     reverse(left.begin(), left.end());

//                     string right;

//                     for (int i = start_pos + 1; i < copyExpression.size(); i++)
//                     {
//                         char pushC = copyExpression[i];

//                         if (pushC == '+' || pushC == '*')
//                             break;
//                         else if (pushC == '-')
//                         {
//                             if (i == start_pos + 1)
//                                 right.push_back(pushC);
//                             else
//                                 break;
//                         }
//                         else
//                             right.push_back(pushC);
//                     }
//                     string replaceStr = left + ch + right;
//                     cout << "left : " << left << " ,right: " << right << endl;
//                     string resultStr = to_string(stoll(left) + stoll(right));
//                     // cout<<replaceStr<<" "<<resultStr<<endl;
//                     size_t replaceIdx = copyExpression.find(replaceStr);
//                     copyExpression.replace(replaceIdx, replaceStr.size(), resultStr);
//                     start_pos = replaceIdx + resultStr.size();
//                     cout << copyExpression << endl;
//                 }
//             }
//             else if (ch == '*')
//             {
//                 size_t start_pos = 0;
//                 while ((start_pos = copyExpression.find(ch, start_pos)) != string::npos)
//                 {
//                     string left;
//                     for (int i = start_pos - 1; i >= 0; i--)
//                     {
//                         char pushC = copyExpression[i];

//                         if (pushC == '+' || pushC == '*')
//                             break;
//                         else if (pushC == '-')
//                         {
//                             if(i==0)
//                                 left.push_back(pushC);
//                             else
//                                 break;
//                         }
//                         else
//                             left.push_back(pushC);
//                     }
//                     reverse(left.begin(), left.end());

//                     string right;

//                     for (int i = start_pos + 1; i < copyExpression.size(); i++)
//                     {
//                         char pushC = copyExpression[i];

//                         if (pushC == '+' || pushC == '*')
//                             break;
//                         else if (pushC == '-')
//                         {
//                             if (i == start_pos + 1)
//                                 right.push_back(pushC);
//                             else
//                                 break;
//                         }
//                         else
//                             right.push_back(pushC);
//                     }

//                     string replaceStr=left+ch+right;
//                     string resultStr=to_string(stoll(left)*stoll(right));

//                     size_t replaceIdx=copyExpression.find(replaceStr);
//                     copyExpression.replace(replaceIdx,replaceStr.size(),resultStr);
//                     start_pos=replaceIdx+resultStr.size();
//                     cout << copyExpression << endl;
//                 }
//             }
//             else{
//                 size_t start_pos=0;
//                 while((start_pos=copyExpression.find(ch,start_pos))!=string::npos){
//                     string left;

//                     for(int i=start_pos-1; i>=0; i--){
//                         char pushC = copyExpression[i];
//                         if (pushC == '+'  || pushC == '*')
//                             break;
//                         else if(pushC=='-'){
//                             left.push_back(pushC);
//                             break;
//                         }
//                         else
//                             left.push_back(pushC);
//                     }
//                     reverse(left.begin(),left.end());

//                     string right;

//                     for(int i=start_pos+1; i<copyExpression.size(); i++){
//                         char pushC=copyExpression[i];
//                         if ( pushC == '-' || pushC == '*')
//                             break;
//                         else if(pushC=='+'){
//                             if(i==start_pos+1)
//                                 right.push_back(pushC);
//                             else
//                                 break;
//                         }
//                         else
//                             right.push_back(pushC);
//                     }

//                     string replaceStr=left+ch+right;
//                     string resultStr;
//                     if(left.empty())
//                         resultStr=to_string(stoll(right)*-1);
//                     else
//                         resultStr=to_string(stoll(left)-stoll(right));

//                     size_t replaceIdx=copyExpression.find(replaceStr);
//                     copyExpression.replace(replaceIdx,replaceStr.size(),resultStr);
//                     start_pos=replaceIdx+resultStr.size();
//                     cout<<copyExpression<<endl;
//                 }
//             }
//         }
//         answer=max(answer,abs(stoll(copyExpression)));
//     } while (next_permutation(operand, operand + 3));
//     return answer;
// }
                        