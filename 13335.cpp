// #include <bits/stdc++.h>
// using namespace std;

// int n,w,l;//트럭수 ,다리길이, 최대하중
// const int MAX=1000;
// int truck[MAX];
// int hour;
// int weight;
// queue<int> q;
// //weight+truck[i]<=l , q.push(truck[i]) weight+=truck[i] , else q.push(0) , q.size()==w q.pop weight-=q.front();
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>n>>w>>l;
//     for(int i=0; i<n ; i++){
//         cin>>truck[i];
//     }
//     int cnt=0;
//     int i=0;
//     while(1){
//         if(cnt==n){
//             cout<<hour<<"\n";
//             return 0;
//         }
//         hour++;
//         if(q.size()==w){
//             if(q.front()!=0){
//                 cnt++;
//                 weight-=q.front();
//             }
//             q.pop();

//         }
//         if(weight+truck[i]<=l){
//             q.push(truck[i]);
//             weight+=truck[i];
//             i++;
//         }
//         else{
//             q.push(0);
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, w, l;
vector<int> truck;
int ret = 0;
void Init()
{
    cin >> n >> w >> l;
    truck.resize(n);
    for (int i = 0; i < n; i++)
        cin >> truck[i];
}
void Solve()
{
    int hWeight = 0;
    int idx = 0;
    queue<int> q;
    int cnt = 0;
    while (1)
    {
        if (q.size() == w)
        {
            if (q.front() != 0)
            {
                cnt++;
                hWeight -= q.front();
            }
            q.pop();
        }
        if (cnt == n)
            break;
        if (hWeight + truck[idx] <= l)
        {
            hWeight += truck[idx];
            q.push(truck[idx++]);
        }
        else
        {
            q.push(0);
        }

        ret++;
    }

    cout << ret + 1 << endl;
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