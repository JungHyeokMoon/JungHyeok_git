#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int length=numbers.size();
    pair<int,int> keyPad [10]={{4,2},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}};
    pair<int,int> left={4,1};
    pair<int,int> right={4,3};
    for(int i=0; i<length; i++){
        int number=numbers[i];
        if(number==1||number==4||number==7){
            left=keyPad[number];
            answer.push_back('L');
        }
        else if(number==3||number==6||number==9){
            right=keyPad[number];
            answer.push_back('R');
        }
        else{
            int hy=keyPad[number].first;
            int hx=keyPad[number].second;

            int lDistance=abs(hy-left.first)+abs(hx-left.second);
            int rDistance=abs(hy-right.first)+abs(hx-right.second);
            // cout<<"hy: "<<hy<<", hx: "<<hx<<" lDistance: "<<lDistance<<", rDistance: "<<rDistance<<endl;
            if(lDistance<rDistance){//왼쪽거리가 더짧은경우
                left=keyPad[number];
                answer.push_back('L');
            }
            else if(lDistance>rDistance){
                right=keyPad[number];
                answer.push_back('R');
            }
            else{//같을경우
                if(hand=="left"){
                    left=keyPad[number];
                    answer.push_back('L');
                }
                else{
                    right=keyPad[number];
                    answer.push_back('R');
                }
            }
        }
        // cout<<"left: "<<left.first<<", "<<left.second<<" right: "<<right.first<<", "<<right.second<<" command: "<<answer[i]<<endl;
    }
    return answer;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(5);
    cout<<solution(arr,"right")<<endl;

    vector<int> arr2;
    arr2.push_back(7);
    arr2.push_back(0);
    arr2.push_back(8);
    arr2.push_back(2);
    arr2.push_back(8);
    arr2.push_back(3);
    arr2.push_back(1);
    arr2.push_back(5);
    arr2.push_back(7);
    arr2.push_back(6);
    arr2.push_back(2);
    cout<<solution(arr2,"left")<<endl;

    vector<int> arr3;

    arr3.push_back(1);
    arr3.push_back(2);
    arr3.push_back(3);
    arr3.push_back(4);
    arr3.push_back(5);
    arr3.push_back(6);
    arr3.push_back(7);
    arr3.push_back(8);
    arr3.push_back(9);
    arr3.push_back(0);

    cout<<solution(arr3,"right")<<endl;
    return 0;
}