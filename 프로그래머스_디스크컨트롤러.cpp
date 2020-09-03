#include <bits/stdc++.h>
using namespace std;
bool Compare(pair<int,int> &a, pair<int,int> & b){
    if(a.second<b.second)
        return true;
    else if(a.second==b.second){
        return a.first<=b.first ? true: false;
    }else
        return false;
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<pair<int,int>> job ;
    for(int i=0; i<jobs.size(); i++)
        job.push_back({jobs[i][0],jobs[i][1]});
    sort(job.begin(),job.end(),Compare);
    int hTime=0;

    while(!job.empty()){
        int length=job.size();
        for(int i=0; i<length; i++){
            if(job[i].first<=hTime){ //작업할수 있음
                hTime+=job[i].second; //작업진행하고
                answer+=(hTime-job[i].first); //요청시간부터 현재시간까지
                job.erase(job.begin()+i);
                break;
            }
            if(i==length-1)
                hTime++; // 진행할 작업이 없다면 시간하나 증가시켜줘야함
        }
    }
    return (answer/jobs.size());
}

int main(){
    cout << solution({ {0,3}, {1,9}, {2,6} }) << '\n';
    
    return 0;
}

