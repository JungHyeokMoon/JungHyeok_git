#include <bits/stdc++.h>
using namespace std;

int gear[4][8]; //위가 0부터 시계방향으로 7까지인덱스 0번톱니바퀴2 1번톱니바퀴 6 || (1,2) <->2,6 || (2,2)<->(3,6) n극은 0 s극이면 1
int k;
int ret=0;
void getscore(){
    for(int i=0; i<4; i++){
        if(gear[i][0]==1){
            ret+=pow(2,i);
        }
    }
    //cout<<"ret : "<<ret<<"\n";
}
void rotation(int num,int direc){
    if(direc==1){
        int temp=gear[num][7];
        for(int i=7; i>=1; i--){
            gear[num][i]=gear[num][i-1];
        }
        gear[num][0]=temp;
    }//시계방향
    else {
        int temp=gear[num][0];
        for(int i=0; i<=6; i++){
            gear[num][i]=gear[num][i+1];
        }
        gear[num][7]=temp;
    }//반시계방향   
}
int reversedirection(int direc){
    if(direc==1)return -1;
    else return 1;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    for(int i=0; i<4; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<8; j++){
            gear[i][j]=temp[j]-'0';
        }
    }
    
    cin>>k;
    for(int i=0; i<k; i++){
        int num;
        int direction;
        cin>>num>>direction; //num은 톱니바퀴번호 direction은 방향 1 시계방향 -1 반시계방향
        num=num-1;
        int rd=reversedirection(direction);
        if(num==0){
            if(gear[0][2]!=gear[1][6]){
                if(gear[1][2]!=gear[2][6]){
                    if(gear[2][2]!=gear[3][6]){
                        rotation(num,direction);
                        rotation(num+1,rd);
                        rotation(num+2,direction);
                        rotation(num+3,rd);
                    }
                    else{
                        rotation(num,direction);
                        rotation(num+1,rd);
                        rotation(num+2,direction);
                    }
                }
                else{
                    rotation(num,direction);
                    rotation(num+1,rd);
                }
            }
            else{
                rotation(0,direction);
            }//다르면 0번만 회전시킴
        }
        else if(num==1){
            if(gear[0][2]!=gear[1][6]){
                rotation(num-1,rd);
            }
            if(gear[1][2]!=gear[2][6]){
                if(gear[2][2]!=gear[3][6]){
                    rotation(num,direction);
                    rotation(num+1,rd);
                    rotation(num+2,direction);
                }
                else{
                    rotation(num,direction);
                    rotation(num+1,rd);
                }
            }
            else{
                rotation(num,direction);
            }
        }
        else if(num==2){
            if(gear[2][2]!=gear[3][6]){
                rotation(num+1,rd);
            }
            if(gear[2][6]!=gear[1][2]){
                if(gear[1][6]!=gear[0][2]){
                    rotation(num,direction);
                    rotation(num-1,rd);
                    rotation(num-2,direction);
                }
                else{
                    rotation(num,direction);
                    rotation(num-1,rd);
                }
            }
            else{
                rotation(num,direction);
            }
        }
        else{
            if(gear[3][6]!=gear[2][2]){
                if(gear[2][6]!=gear[1][2]){
                    if(gear[1][6]!=gear[0][2]){
                        rotation(num,direction);
                        rotation(num-1,rd);
                        rotation(num-2,direction);
                        rotation(num-3,rd);
                    }
                    else{
                        rotation(num,direction);
                        rotation(num-1,rd);
                        rotation(num-2,direction);
                    }
                
                }
                else{
                    rotation(num,direction);
                    rotation(num-1,rd);    
                }
            }
            else{
                rotation(num,direction);
            }
        }
        
    }
    getscore();
    cout<<ret<<"\n";
    //같은극이면 가만히있음 ,다른극이면 회전의 반대방향으로 회전한다.
    return 0;
}