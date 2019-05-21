#include <iostream>
#include <list>
using namespace std;
void josephus(int n,int k){
    list<int> solve;
    for(int i=1; i<=n; i++){
        solve.push_back(i);
    }
    list<int>::iterator suicide=solve.begin();

    while(n>2){
        suicide=solve.erase(suicide); //erase는 가리키고있는 원소지우고 다음위치반환
        if(suicide==solve.end()){
            suicide=solve.begin();
        }
        n--;
        for(int i=0; i<k-1; i++){
            suicide++;
            if(suicide==solve.end()){
                suicide=solve.begin();
            }
        } //k-1번 why? erase에서 이미 뒤로한칸물려줬기때문
    }
    cout<<solve.front()<<" "<<solve.back()<<endl;

}
int C,N,K;
int main(){
    cin>>C;
    for(int i=0; i<C; i++){
        cin>>N>>K;
        josephus(N,K);
    }

    return 0;
}