#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    //오름차순 정렬
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int ABLenth=A.size();
    //뒤에서 부터 훓을포인터
    int A_Pointer=ABLenth-1;
    int B_Pointer=ABLenth-1;
    
    
    for(int i=0; i<ABLenth;i++){
        //B의 현재 최댓값이 A의 최댓값보다 클경우 답증가, 포인터를 앞으로 하나 땡겨서 최댓값의 범위를 줄여줌
        if(A[A_Pointer]<B[B_Pointer]){
            B_Pointer--;
            answer++;
        }
        //A는 답이 증가할때나, 답이 증가하지 않을때나 계속해서 감소시켜줘야 비교가 가능하다.
        A_Pointer--;
    }
    return answer;
}

int main(){
    cout<<solution({5,1,3,7},{2,2,6,8})<<endl;
    return 0;
}
