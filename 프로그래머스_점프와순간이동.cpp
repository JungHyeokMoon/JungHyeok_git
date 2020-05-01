#include <bits/stdc++.h>
using namespace std;

int solution(int n)
{
    int ans = 987654321;
    queue<pair<int, int>> q; //여태까지 거리, 건전지사용량
    q.push({1, 1});
    // vector<bool> visited(2 * (n + 1), false);
    // visited[0] = true;
    // visited[1] = true;
    while (!q.empty())
    {
        int hd = q.front().first;
        int hc = q.front().second;
        cout<<"hc: "<<hc<<" , hd : "<<hd<<endl;
        q.pop();

        if (hd == n)
        {
            ans = min(ans, hc);
            continue;
        }
        if ((hd + 1 <= n))
        {
            q.push({hd + 1, hc + 1});
            // visited[hd + 1] = true;
        }
        if ((hd * 2 <= n))
        {
            q.push({2 * hd, hc});
            // visited[2 * hd] = true;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    solution(n);

    return 0;
}
//시간초과코드

#include <bits/stdc++.h>
using namespace std;

int solution(int n)
{
    int ans = 0;
	while(n!=0){
        if(n%2==0){
            n/=2;
        }else{
            n--;
            ans++;
        }
    }
    return ans;
}
//매우쉬운..