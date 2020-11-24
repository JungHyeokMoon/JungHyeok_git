#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    
    int length=numbers.size();
    set<int> tempSet;
    for(int i=0; i<length-1; i++){
        int firstNumber=numbers[i];
        for(int j=i+1; j<length; j++){
            tempSet.insert(firstNumber+numbers[j]);
        }
    }
    vector<int> answer(tempSet.begin(),tempSet.end());
    sort(answer.begin(),answer.end(),[](auto a , auto b){
        return a<b;
    });
    return answer;
}

int main(){
    vector<int> answer=solution({2,1,3,4,1});
    for(auto num : answer)
        cout<<num<<" ";
    return 0;
}