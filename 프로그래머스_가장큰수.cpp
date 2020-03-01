#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool compare(string & a, string & b){
    int leng_A=a.size();
    int leng_B=b.size();
    int i=0, j=0;
    while(1){
        if(a[i]>b[j]){
            return true;
        }
        else if(a[i]<b[j]){
            return false;
        }
        else{
            if(i<leng_A-1){
                i++;
            }
            if(j<leng_B-1){
                j++;
            }
        }
    }
}
bool comapre(int &a, int &b){
    
}
string solution(vector<int> numbers) {
    string answer = "";
    int length=numbers.size();
    vector<string> arr(length);
    for(int i=0; i<length; i++){
        arr[i]=to_string(numbers[i]);
    }
    sort(arr.begin(),arr.end(),compare);
    for(int i=0; i<length ; i++){
        answer+=arr[i];
    }
    return answer;
}
//시간초과코드

//참고한코드 정렬함수 오버로딩했는데, 두문자열더해서 더큰것이 앞으로오도록
//10+6 106  6+10 610 요렇게
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool compare(string &a, string &b){
    return a+b>b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    int length=numbers.size();
    vector<string> arr(length);
    for(int i=0; i<length; i++){
        arr[i]=to_string(numbers[i]);
    }
    sort(arr.begin(),arr.end(),compare);
    if(arr[0]=="0") return "0"; //0만 여러개일경우 주석처리
    for(int i=0; i<length ; i++){
        answer+=arr[i];
    }
    return answer;
}