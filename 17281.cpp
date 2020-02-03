#include <bits/stdc++.h>
using namespace std;
int n;
int baseball[50][9];
bool selected[9];
int batting_order[9];
int ret = -987654321;
void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> baseball[i][j];
        }
    }
    batting_order[3] = 0;
    selected[3] = true;
}
void Game()
{
    int base[3];
    int Score = 0;
    int Start_Player = 0;

    for (int i = 0; i < n; i++)
    {
        int outcnt = 0;
        memset(base, false, sizeof(base));
        while (1)
        {
            if(baseball[i][batting_order[Start_Player]]==0){
                outcnt++;
            }
            else if(baseball[i][batting_order[Start_Player]]==1){
                for(int k=2; k>=0; k--){
                    if(base[k]==1){
                        if(k==2){
                            base[k]=0;
                            Score++;
                        }
                        else{
                            base[k+1]=1;
                            base[k]=0;
                        }
                    }
                }
                base[0]=1;
            }
            else if(baseball[i][batting_order[Start_Player]]==2){
                for(int k=2; k>=0; k--){
                    if(base[k]==1){
                        if(k==2||k==1){
                            base[k]=0;
                            Score++;
                        }
                        else{
                            base[k+2]=1;
                            base[k]=0;
                        }
                    }
                }
                base[1]=1;
            }
            else if(baseball[i][batting_order[Start_Player]]==3){
                for(int k=0; k<3; k++){
                    if(base[k]==1){
                        base[k]=0;
                        Score++;
                    }
                }
                base[2]=1;
            }
            else{
                for(int k=0; k<3; k++){
                    if(base[k]==1){
                        base[k]=0;
                        Score++;
                    }
                }
                Score++;
            }
            Start_Player=(Start_Player+1)%9;
            if(outcnt==3){
                break;
            }
        }
    }

    ret = max(ret, Score);
}
void Make_Batting_order(int playernum)
{
    if (playernum == 9)
    {
        Game();
        return;
    }

    for (int i = 0; i < 9; i++)
    {
        if (selected[i])
            continue;
        selected[i] = true;
        batting_order[i] = playernum;
        Make_Batting_order(playernum + 1);
        selected[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Make_Batting_order(1);
    cout << ret << "\n";
    return 0;
}
