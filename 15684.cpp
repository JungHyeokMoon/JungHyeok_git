#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, h;
bool ladder[11][30];
int ret=1e9;
void Init() {
    cin>>n>>m>>h;
    for (int i=0; i<m; i++) {
        int a, b;
        cin>>a>>b;
        ladder[b][a]=true;
    }
}
bool LadderGame() {
    for (int i=1; i<=n; i++) {
        int hIdx=i;
        for (int j=1; j<=h; j++) {
            if (ladder[hIdx][j]==true)hIdx++;
            else if (ladder[hIdx-1][j]==true)hIdx--;
        }
        if (hIdx!=i) return false;
    }
    return true;
}
void SelectLine(int idx, int cnt) {
    if (cnt>=4)
        return;

    if (LadderGame()) {
        ret=min(ret, cnt);
        return;
    }

    for (int i=idx; i<=h; i++) {
        for (int j=1; j<n; j++) {
            if (ladder[j][i]||ladder[j-1][i]||ladder[j+1][i])continue;
            ladder[j][i]=true;
            SelectLine(i, cnt+1);
            ladder[j][i]=false;
        }
    }
}
void Solve() {
    SelectLine(1, 0);
    if (ret==1e9) cout<<-1<<endl;
    else cout<<ret<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    Solve();
    return 0;
}