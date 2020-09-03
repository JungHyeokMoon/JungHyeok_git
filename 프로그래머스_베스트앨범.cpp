#include <bits/stdc++.h>
using namespace std;

bool Compare(pair<int, string> &a ,pair<int, string> & b){
    if(a.first>b.first)
        return true;
    return false;
}
bool Compare2(pair<int, int> & a, pair<int,int > & b){
    if(a.first>b.first)
        return true;
    else if(a.first==b.first){
        return a.second<b.second;
    }
    else
        return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int length=genres.size();
    map<string ,int> m;
    for(int i=0; i<length; i++)
        m[genres[i]]+=plays[i];

    vector<pair<int,string>> v;
    for(auto i: m)
        v.push_back({i.second,i.first});
    
    sort(v.begin(),v.end(),Compare);

    vector<vector<pair<int,int>>> v2;
    v2.resize(v.size());
    for(int i=0; i<v.size(); i++){
        string genre=v[i].second;
        for(int j=0; j<length; j++){
            if(genre==genres[j]){
                v2[i].push_back({plays[j],j}); //재생횟수 고유부호
            }
        }
    }

    for(int i=0; i<v2.size(); i++){
        sort(v2[i].begin(),v2[i].end(),Compare2);
        // for(int j=0; j<v2[i].size(); j++){
        //     cout<<v2[i][j].first<<" "<<v2[i][j].second<<", ";
        // }
        // cout<<endl;
        for(int j=0; j<v2[i].size(); j++){
            if(j==2)break;
            answer.push_back(v2[i][j].second);
        }
    }
    return answer;
}

int main(){
    vector<string> genres;
    genres.push_back("classic");
    genres.push_back("pop");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");

    vector<int> plays;
    plays.push_back(500);
    plays.push_back(600);
    plays.push_back(150);
    plays.push_back(800);
    plays.push_back(2500);
    vector<int> Answer=solution(genres,plays);
    for(auto i :Answer)
        cout<<i<<" ";
    return 0;
}