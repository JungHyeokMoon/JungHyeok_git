#include <iostream>
#include <queue>
using namespace std;
int idx=9;
long long answer[1000000+1];
int main(){
    int n;
    scanf("%d\n", &n);

    queue<long long> q;
    for(int i=0; i<=9; i++){
        answer[i]=i;
        q.push(i);
    }//

    while(!q.empty()){
        int lastnumber=q.front();
        q.pop();

        for(int i=0; i<lastnumber; i++){
            q.push(lastnumber*10+i);
            answer[++idx]=lastnumber*10+i;
        }

    }

    if(answer[0]==0){
        printf("-1\n");
    }
    else
        cout<<answer[n]<<endl;
    
    return 0;
}