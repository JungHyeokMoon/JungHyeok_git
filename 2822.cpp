#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    vector<pair<int,int>> v(8);//���� ,������ȣ

    for(int i=0; i<8; i++){
        cin>>v[i].first;
        v[i].second=i+1;
    }
    
    int sum=0;
    sort(v.begin(), v.end(), greater<pair<int, int>>());//������������
    vector<int> idx;

    for(int i=0; i<5; i++){
        sum=sum+v[i].first;
        idx.push_back(v[i].second);
    }

    printf("%d\n",sum);

    sort(idx.begin(),idx.end());
    for(int i=0; i<5; i++)
        printf("%d ",idx[i]);
    return 0;

}