#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int n;
int color[1001][3];
int dp[1001][3];

int solve(int idx, int col){
   if (idx == n)
      return 0;

   int &ret = dp[idx][col];
   if (ret != -1)return ret;

   if (col == 0)ret = min(solve(idx + 1, 1) , solve(idx + 1, 2) );
   else if (col == 1)ret = min(solve(idx + 1, 0) , solve(idx + 1, 2) );
   else ret = min(solve(idx + 1, 0), solve(idx + 1, 1));

   return ret=ret+color[idx][col];
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> n;
   for (int i = 0; i<n; i++){
      for (int j = 0; j<3; j++){
         cin >> color[i][j];
      }
   }
   

   memset(dp, -1, sizeof(dp));

   //cout << solve(0, 0) << "\n";

   int ans = 987654321;
   ans = min(ans, solve(0, 0));
   memset(dp, -1, sizeof(dp));
   ans = min(ans, solve(0, 1));
   memset(dp, -1, sizeof(dp));
   ans = min(ans, solve(0,2));

   cout << ans << "\n";

   //이풀이는 처음색깔은못정해준다

}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int N, cost[1000][3], dp[1001][4];

int RGB(int pos, int prev = 3){
   int& ret = dp[pos][prev];
   if (ret != -1) return ret;
   if (pos == N) return ret = 0;

   ret = INF;
   for (int i = 0; i<3; i++)
      if (prev != i) ret = min(ret, RGB(pos + 1, i) + cost[pos][i]);
   return ret;
}

int main(){
   scanf("%d", &N);
   for (int i = 0; i<N; i++)
      for (int j = 0; j<3; j++)
         scanf("%d", &cost[i][j]);
   memset(dp, -1, sizeof(dp));
   printf("%d\n", RGB(0));
}
//블로그 풀이보면 함수에 디폴트값줘서 그 이후로 진행해주고있다 이거 참고하면될듯