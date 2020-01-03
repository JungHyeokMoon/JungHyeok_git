#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int star = 2 * n - 1;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        if (i == n)
        {
            for(int j=1 ; j<=n-1; j++){
                cout<<" ";
            }
            cout << "*";
            star += 2;
        }
        else if (i < n)
        {
            for(int j=1 ; j<=i-1; j++){
                cout<<" ";
            }
            for (int j = 1; j <= star; j++)
            {
                cout <<"*";
            }
            star-=2;
        }
        else{
            for(int j=2*n-i; j>1; j--){
                cout<<" ";
            }
            for (int j = 1; j <= star; j++)
            {
                cout <<"*";
            }
            star+=2;
        }
        cout<<"\n";
    }
    return 0;
}