#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string king,stone;
int n;
vector<string> arr;
bool isinside(char x, int y){
    if(x>='A' && x<='H' && y>=1 && y<=8){
        return true;
    }
    return false;
}
void Input(){
    cin>>king>>stone>>n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}
pair<int,int> direction(string s){
    if(s=="R"){//오른쪽
        return {1,0};
    }else if(s=="L"){//왼쪽
        return {-1,0};
    }else if(s=="B"){//아래
        return {0,-1};
    }else if(s=="T"){//위
        return {0,1};
    }else if(s=="RT"){//오른쪽위대각선
        return {1,1};
    }else if(s=="LT"){//왼쪽위대각선
        return {-1,1};
    }else if(s=="RB"){//오른쪽아래대각선
        return {1,-1};
    }else if(s=="LB"){//왼쪽아래 대각선
        return {-1,-1};
    }
}
void Solve(){
    for(int i=0; i<n; i++){
        // cout<<"before : "<<king<<" , "<<stone<<endl;
        pair<int,int> d=direction(arr[i]);
        // cout<<"direction : "<<d.first<<" "<<d.second<<endl;

        // if(!isinside(char(king[0]+d.first),(king[1]-'0')+d.second) || !isinside(char(stone[0]+d.first),(stone[1]-'0')+d.second)) continue;
        if(!isinside(char(king[0]+d.first),(king[1]-'0')+d.second))continue; //왕의다음칸체크
        string kingtemp;
        kingtemp.resize(2);
        kingtemp[0]=char(king[0]+d.first);
        kingtemp[1]=((king[1]-'0')+d.second+'0');
        // string stonetemp;
        // stonetemp.resize(2);
        if(kingtemp==stone){//왕의 다음칸이 돌의위치랑같으면 돌을 같은방향으로옮겨야한다
            // stonetemp[0]=char(stone[0]+d.first);
            // stonetemp[1]=((stone[1]-'0')+d.second+'0');
            if(!isinside(char(stone[0]+d.first),(stone[1]-'0')+d.second))continue;//근데 범위가 벗어나면 없던셈쳐야함 
            stone[0]=char(stone[0]+d.first);
            stone[1]=((stone[1]-'0')+d.second+'0');//돌도 방향따라 한칸옮겨주고
        }
        
        king[0]=char(king[0]+d.first);
        king[1]=((king[1]-'0')+d.second+'0');//왕옮겨줌 , 왕은 범위가 벗어나는게아니라면 움직임계속
        
        
    }
    cout<<king<<endl<<stone<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}