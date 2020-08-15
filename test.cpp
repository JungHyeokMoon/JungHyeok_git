#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<vector<int>> cube;
vector<vector<int>> face;
int row, col;
void Init(){
    cin>>row>>col;
    cube.resize(row,vector<int>(col));

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            cin>>cube[i][j];

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<cube[i][j]<<" ";
        }
        cout<<endl;
    }

    swap(row,col);
    face.resize(row,vector<int>(col));
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            face[i][j]=cube[col-1-j][i];

    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<face[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<row; i++)
        face[i].clear();
    face.clear();

    // cout<<face[0].size()<<" "<<face.size()<<endl;

    face.resize(row,vector<int>(col));

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            face[i][j]=cube[j][row-1-i];


    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<face[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    return 0;
}