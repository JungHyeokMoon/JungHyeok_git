#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int length=heights.size();
    stack<pair<int,int>> stk;
    for(int i=0; i<length ;i++){
        stk.push({heights[i],i+1}); //높이, 인덱스
    }
    bool flag=false;
    while(stk.size()!=1){
        int height_check=stk.top().first;
        int height_check_idx=stk.top().second;
        flag=false;
        stk.pop();
        stack<pair<int,int>> temp;//높이,인덱스
        while(!stk.empty()){
            int temp_height=stk.top().first;
            int temp_idx=stk.top().second;
            if(temp_height>height_check){
                answer.push_back(temp_idx);
                flag=true;
                break;
            }
            else{
                temp.push({temp_height,temp_idx});
                stk.pop();
            }
        }
        while(!temp.empty()){
            stk.push(temp.top());
            temp.pop();
        }//빼냈던것들 다시넣어줘야함
        if(!flag){
            answer.push_back(0);
        }
    }
    //첫타워는 무조건 0
    // answer.push_back(0);
    answer.push_back(0);
    reverse(answer.begin(),answer.end());
    return answer;
}
//다른사람풀이참조법 좀더 간편하게

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int length=heights.size();
    for(int i=length-1; i>=0; i--){
        bool flag=false;
        for(int j=i-1; j>=0; j--){
            if(heights[j]>heights[i]){
                answer.push_back(j+1);
                flag=true;
                break;
            }
        }
        if(!flag){
            answer.push_back(0);
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
// ---- 인풋범위가커질경우
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int length=heights.size();
    stack<pair<int,int>>stk; //높이 인덱스
    for(int i=0; i<length; i++){
        while(!stk.empty()){
            if(stk.top().first>heights[i]){
                answer.push_back(stk.top().second);
                break;
            }
            stk.pop();
        }
        if(stk.empty()){
            answer.push_back(0);
        }
        stk.push({heights[i],i+1});
    }
    return answer;
}