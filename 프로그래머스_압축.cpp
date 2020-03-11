#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<string> arr;
int length;
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
//A B C D F E F G H  I  J  K  L  N  M  O  P  Q  R  S  T  U  W  X  Y  Z 
void Init(){
    char A='A';
    arr.resize(27);
    for(int i=1; i<=26; i++){
        arr[i]=A+(i-1);
    }
}
int Findstring(string input){
    int arrlength=arr.size();
    for(int i=1; i<length ; i++){
        if(arr[i]==input){
            return i;
        }
    }
    return -1;
}
vector<int> solution(string msg) {
    vector<int> answer;
    length=msg.size();
    Init();
    for(int i=0; i<length ; i++){
        string temp="";
        int previndex=0;
        int cnt=-1;
        for(int j=i; j<length ; j++){
            temp+=msg[j];
            int plusnumber=Findstring(temp);
            if(plusnumber!=-1){
                previndex=plusnumber;
                cnt++;
            }
            else{
                arr.push_back(temp);
                answer.push_back(previndex);
                i=i+cnt;
                break;
            }
        }
    }
    return answer;
}
//실패한코드 마지막 까지 도달했을때랑 인덱스 관리실패함
//아래는 참조한코드 https://chaibin0.tistory.com/entry/%EC%95%95%EC%B6%95

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<string> arr;
int length;
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
//A B C D F E F G H  I  J  K  L  N  M  O  P  Q  R  S  T  U  W  X  Y  Z 
void Init(){
    char A='A';
    arr.resize(27);
    for(int i=1; i<=26; i++){
        arr[i]=A+(i-1);
    }
}
vector<int> solution(string msg) {
    vector<int> answer;
    length=msg.size();
    Init();
    vector<string>::iterator iter;
    bool flag;
    for(int i=0; i<length ; i++){
        string temp="";
        int pushnum=0;
        flag=true;
        while(flag){
            temp+=msg[i];
            iter=find(arr.begin(),arr.end(),temp);
            if(iter!=arr.end()){
                pushnum=iter-arr.begin();
                i++;
            }
            else{
                flag=false;
                answer.push_back(pushnum);
                arr.push_back(temp);
                i--;
            }
        }
        
    }
    return answer;
}