#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<pair<int,int>,int>> coordi;
int camera[8][8];
int C_camera[8][8];
int Turn_order[8];
bool isvisited[8][8];
int ret=987654321;
void copy_map(){
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            C_camera[i][j]=camera[i][j];
        }
    }
}
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 &&x<m){
        return true;
    }
    return false;
}
int brute_force(){
    for(int i=0; i<coordi.size(); i++){
        int Turn=Turn_order[i];
        int hy=coordi[i].first.first;
        int hx=coordi[i].first.second;
        int camerakind=coordi[i].second;
        if(camerakind==1){ 
            if(Turn==0){//오른쪽
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hx++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx]!=0)continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }else if(Turn==1){
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hy++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }//아래쪽
            }else if(Turn==2){//왼쪽
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hx--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }else{//위쪽
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hy--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }

        }
        else if(camerakind==2){
            if(Turn==0|| Turn==2){
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hx++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx]!=0)continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }//오른쪽
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hx--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }//왼쪽
            }//양옆
            else{
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hy--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hy++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }//아래쪽
            }//위아래
        }
        else if(camerakind==3){
            if(Turn==0){//위 오른쪽
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hy--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hx++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }else if(Turn==1){//오른, 아래쪽
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hx++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hy++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }else if(Turn==2){ //아래쪽, 왼쪽
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hy++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hx--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }else{//왼쪽, 위쪽
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hx--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hy--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }
        }
        else if(camerakind==4){
            if(Turn==0){//왼 위 오른
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hx--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hy--;//
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hx++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }else if(Turn==1){//위 오른 아래
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hy--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hx++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy; 
                Temp_hx=hx;
                while(1){
                    Temp_hy++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }else if(Turn==2){//오른 아래 왼
                int Temp_hy=hy;
                int Temp_hx=hx;
                while(1){
                    Temp_hx++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy; 
                Temp_hx=hx;
                while(1){
                    Temp_hy++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hx--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }else{//아래 왼 위
                int Temp_hy=hy; 
                int Temp_hx=hx;
                while(1){
                    Temp_hy++;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hx--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
                Temp_hy=hy;
                Temp_hx=hx;
                while(1){
                    Temp_hy--;
                    if(!isinside(Temp_hy,Temp_hx))break;
                    if(C_camera[Temp_hy][Temp_hx]==6)break;
                    if(C_camera[Temp_hy][Temp_hx])continue;
                    C_camera[Temp_hy][Temp_hx]=7;
                }
            }
        }
        else{
            int Temp_hy=hy; 
            int Temp_hx=hx;
            while(1){
                Temp_hy++;
                if(!isinside(Temp_hy,Temp_hx))break;
                if(C_camera[Temp_hy][Temp_hx]==6)break;
                if(C_camera[Temp_hy][Temp_hx])continue;
                C_camera[Temp_hy][Temp_hx]=7;
            }
            Temp_hy=hy;
            Temp_hx=hx;
            while(1){
                Temp_hx--;
                if(!isinside(Temp_hy,Temp_hx))break;
                if(C_camera[Temp_hy][Temp_hx]==6)break;
                if(C_camera[Temp_hy][Temp_hx])continue;
                C_camera[Temp_hy][Temp_hx]=7;
            }
            Temp_hy=hy;
            Temp_hx=hx;
            while(1){
                Temp_hy--;
                if(!isinside(Temp_hy,Temp_hx))break;
                if(C_camera[Temp_hy][Temp_hx]==6)break;
                if(C_camera[Temp_hy][Temp_hx])continue;
                C_camera[Temp_hy][Temp_hx]=7;
            }
            Temp_hy=hy;
            Temp_hx=hx;
            while(1){
                Temp_hx++;
                if(!isinside(Temp_hy,Temp_hx))break;
                if(C_camera[Temp_hy][Temp_hx]==6)break;
                if(C_camera[Temp_hy][Temp_hx])continue;
                C_camera[Temp_hy][Temp_hx]=7;
            }
        }//turn 노상관
    }


    int count=0;
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(C_camera[i][j]==0){
                count++;
            }
        }
    }
    //cout<<count<<"\n";
    return count;
}
void make_Turn_order(int cnt){
    if(cnt==coordi.size()){
        memset(isvisited,false,sizeof(isvisited));
        copy_map();
        int size=brute_force();
        ret=min(ret,size);
        
        return ;
    }
    for(int Turn=0; Turn<4; Turn++){
        Turn_order[cnt]=Turn;
        make_Turn_order(cnt+1);
    } //0오른쪽 1 아래쪽 2 왼쪽 3 위쪽
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>camera[i][j];
            if(camera[i][j]>=1 && camera[i][j]<=5){
                coordi.push_back({{make_pair(i,j)},camera[i][j]});
            }//카메라종류 0은 빈칸 6은벽 12345 카메라종류
        }
    }
    
    make_Turn_order(0);

    
    cout<<ret<<"\n";

    return 0;
}