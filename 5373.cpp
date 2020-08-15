#include <bits/stdc++.h>
#define endl "\n"
#define White 'w'
#define Yellow 'y'
#define Red 'r'
#define Orange 'o'
#define Green 'g'
#define Blue 'b'
using namespace std;

vector<vector<vector<char>>> cube;
vector<string> Rotation;
int n;
void cubePaint(char color)
{
    vector<vector<char>> face(3, vector<char>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            face[i][j] = color;

    cube.push_back(face);
}
void Init()
{
    cin >> n;
    cubePaint(White);
    cubePaint(Green);
    cubePaint(Red);
    cubePaint(Blue);
    cubePaint(Orange);
    cubePaint(Yellow);
}
void Output(vector<vector<vector<char>>> cube)
{ //답출력
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << cube[0][i][j];
        }
        cout << endl;
    }
}
void Test(vector<vector<vector<char>>> cube)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "   ";
        for (int j = 0; j < 3; j++)
        {
            cout << cube[0][i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int k = 1; k <= 4; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << cube[k][i][j];
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "   ";
        for (int j = 0; j < 3; j++)
        {
            cout << cube[5][i][j];
        }
        cout << endl;
    }
}
void ClockRotation(int idx, vector<vector<vector<char>>> &cube)
{
    vector<vector<char>> face(3, vector<char>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            face[i][j] = cube[idx][3 - 1 - j][i];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[idx][i][j] = face[i][j];
}
void CounterClockRotation(int idx, vector<vector<vector<char>>> &cube)
{
    vector<vector<char>> face(3, vector<char>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            face[i][j] = cube[idx][j][3 - 1 - i];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[idx][i][j] = face[i][j];
}
void Rotate(vector<vector<vector<char>>> cube, int length)
{
    //cube 0 윗면, cube 1 아랫면, cube 2 앞면, cube 3 뒷면,cube 4 왼쪽면,cube 5 오른쪽면
    for (int i = 0; i < length; i++)
    {
        char face = Rotation[i][0];
        char dir = Rotation[i][1];
        if (face == 'U')
        {
            if (dir == '+')
            {
                ClockRotation(0,cube);

                char temp0=cube[3][0][0];
                char temp1=cube[3][0][1];
                char temp2=cube[3][0][2];
                cube[3][0][0]=cube[4][0][0];
                cube[3][0][1]=cube[4][0][1];
                cube[3][0][2]=cube[4][0][2];

                cube[4][0][0]=cube[1][0][0];
                cube[4][0][1]=cube[1][0][1];
                cube[4][0][2]=cube[1][0][2];

                cube[1][0][0]=cube[2][0][0];
                cube[1][0][1]=cube[2][0][1];
                cube[1][0][2]=cube[2][0][2];

                cube[2][0][0]=temp0;
                cube[2][0][1]=temp1;
                cube[2][0][2]=temp2;
            }
            else
            {
                CounterClockRotation(0,cube);

                char temp0=cube[2][0][0];
                char temp1=cube[2][0][1];
                char temp2=cube[2][0][2];
                cube[2][0][0]=cube[1][0][0];
                cube[2][0][1]=cube[1][0][1];
                cube[2][0][2]=cube[1][0][2];

                cube[1][0][0]=cube[4][0][0];
                cube[1][0][1]=cube[4][0][1];
                cube[1][0][2]=cube[4][0][2];
                
                cube[4][0][0]=cube[3][0][0];
                cube[4][0][1]=cube[3][0][1];
                cube[4][0][2]=cube[3][0][2];

                cube[3][0][0]=temp0;
                cube[3][0][1]=temp1;
                cube[3][0][2]=temp2;
            }
        }
        else if (face == 'D')
        {
            if (dir == '+')
            {
                ClockRotation(5,cube);

                char temp0=cube[3][2][0];
                char temp1=cube[3][2][1];
                char temp2=cube[3][2][2];
                cube[3][2][0]=cube[2][2][0];
                cube[3][2][1]=cube[2][2][1];
                cube[3][2][2]=cube[2][2][2];

                cube[2][2][0]=cube[1][2][0];
                cube[2][2][1]=cube[1][2][1];
                cube[2][2][2]=cube[1][2][2];

                cube[1][2][0]=cube[4][2][0];
                cube[1][2][1]=cube[4][2][1];
                cube[1][2][2]=cube[4][2][2];

                cube[4][2][0]=temp0;
                cube[4][2][1]=temp1;
                cube[4][2][2]=temp2;

            }
            else
            {//패턴다름
                CounterClockRotation(5,cube);

                char temp0=cube[1][2][2];
                char temp1=cube[1][2][1];
                char temp2=cube[1][2][0];
                cube[1][2][0]=cube[2][2][0];
                cube[1][2][1]=cube[2][2][1];
                cube[1][2][2]=cube[2][2][2];

                cube[2][2][0]=cube[3][2][0];
                cube[2][2][1]=cube[3][2][1];
                cube[2][2][2]=cube[3][2][2];

                cube[3][2][0]=cube[4][2][0];
                cube[3][2][1]=cube[4][2][1];
                cube[3][2][2]=cube[4][2][2];
                
                cube[4][2][0]=temp2;
                cube[4][2][1]=temp1;
                cube[4][2][2]=temp0;

            }
        }
        else if (face == 'F')
        {
            if (dir == '+')
            {
                ClockRotation(2,cube);

                char temp0=cube[0][2][0];
                char temp1=cube[0][2][1];
                char temp2=cube[0][2][2];

                cube[0][2][0]=cube[1][2][2];
                cube[0][2][1]=cube[1][1][2];
                cube[0][2][2]=cube[1][0][2];

                cube[1][0][2]=cube[5][0][0];
                cube[1][1][2]=cube[5][0][1];
                cube[1][2][2]=cube[5][0][2];

                cube[5][0][0]=cube[3][2][0];
                cube[5][0][1]=cube[3][1][0];
                cube[5][0][2]=cube[3][0][0];

                cube[3][0][0]=temp0;
                cube[3][1][0]=temp1;
                cube[3][2][0]=temp2;
            }

            else
            {
                CounterClockRotation(2,cube);

                char temp0=cube[1][0][2];
                char temp1=cube[1][1][2];
                char temp2=cube[1][2][2];
                cube[1][0][2]=cube[0][2][2];
                cube[1][1][2]=cube[0][2][1];
                cube[1][2][2]=cube[0][2][0];

                cube[0][2][0]=cube[3][0][0];
                cube[0][2][1]=cube[3][1][0];
                cube[0][2][2]=cube[3][2][0];

                cube[3][0][0]=cube[5][0][2];
                cube[3][1][0]=cube[5][0][1];
                cube[3][2][0]=cube[5][0][0];

                cube[5][0][0]=temp0;
                cube[5][0][1]=temp1;
                cube[5][0][2]=temp2;
            }
        }
        else if (face == 'B')
        {
            if (dir == '+')
            {
                ClockRotation(4,cube);

                char temp0=cube[1][0][0];
                char temp1=cube[1][1][0];
                char temp2=cube[1][2][0];

                cube[1][0][0]=cube[0][0][2];
                cube[1][1][0]=cube[0][0][1];
                cube[1][2][0]=cube[0][0][0];

                cube[0][0][0]=cube[3][0][2];
                cube[0][0][1]=cube[3][1][2];
                cube[0][0][2]=cube[3][2][2];

                cube[3][0][2]=cube[5][2][2];
                cube[3][1][2]=cube[5][2][1];
                cube[3][2][2]=cube[5][2][0];

                cube[5][2][0]=temp0;
                cube[5][2][1]=temp1;
                cube[5][2][2]=temp2;
            }
            else
            {
                CounterClockRotation(4,cube);
                
                char temp0=cube[3][2][2];
                char temp1=cube[3][1][2];
                char temp2=cube[3][0][2];
                cube[3][0][2]=cube[0][0][0];
                cube[3][1][2]=cube[0][0][1];
                cube[3][2][2]=cube[0][0][2];

                cube[0][0][0]=cube[1][2][0];
                cube[0][0][1]=cube[1][1][0];
                cube[0][0][2]=cube[1][0][0];

                cube[1][0][0]=cube[5][2][0];
                cube[1][1][0]=cube[5][2][1];
                cube[1][2][0]=cube[5][2][2];

                cube[5][2][0]=temp0;
                cube[5][2][1]=temp1;
                cube[5][2][2]=temp2;
                
            }
        }
        else if (face == 'L')
        {
            if (dir == '+'){
                ClockRotation(1,cube);

                char temp0=cube[2][2][0];
                char temp1=cube[2][1][0];
                char temp2=cube[2][0][0];

                cube[2][0][0]=cube[0][0][0];
                cube[2][1][0]=cube[0][1][0];
                cube[2][2][0]=cube[0][2][0];

                cube[0][0][0]=cube[4][2][2];
                cube[0][1][0]=cube[4][1][2];
                cube[0][2][0]=cube[4][0][2];

                cube[4][0][2]=cube[5][2][0];
                cube[4][1][2]=cube[5][1][0];
                cube[4][2][2]=cube[5][0][0];

                cube[5][0][0]=temp2;
                cube[5][1][0]=temp1;
                cube[5][2][0]=temp0;
            }
            else
            {
                CounterClockRotation(1,cube);
                
                char temp0=cube[0][2][0];
                char temp1=cube[0][1][0];
                char temp2=cube[0][0][0];

                cube[0][0][0]=cube[2][0][0];
                cube[0][1][0]=cube[2][1][0];
                cube[0][2][0]=cube[2][2][0];

                cube[2][0][0]=cube[5][0][0];
                cube[2][1][0]=cube[5][1][0];
                cube[2][2][0]=cube[5][2][0];

                cube[5][0][0]=cube[4][2][2];
                cube[5][1][0]=cube[4][1][2];
                cube[5][2][0]=cube[4][0][2];

                cube[4][0][2]=temp0;
                cube[4][1][2]=temp1;
                cube[4][2][2]=temp2;
                

            }
        }
        else
        { //R
            if (dir == '+')
            {
                ClockRotation(3,cube);
                
                char temp0=cube[0][2][2];
                char temp1=cube[0][1][2];
                char temp2=cube[0][0][2];

                cube[0][0][2]=cube[2][0][2];
                cube[0][1][2]=cube[2][1][2];
                cube[0][2][2]=cube[2][2][2];

                cube[2][0][2]=cube[5][0][2];
                cube[2][1][2]=cube[5][1][2];
                cube[2][2][2]=cube[5][2][2];

                cube[5][0][2]=cube[4][2][0];
                cube[5][1][2]=cube[4][1][0];
                cube[5][2][2]=cube[4][0][0];

                cube[4][0][0]=temp0;
                cube[4][1][0]=temp1;
                cube[4][2][0]=temp2;

            }
            else
            {
                CounterClockRotation(3,cube);

                char temp0=cube[2][0][2];
                char temp1=cube[2][1][2];
                char temp2=cube[2][2][2];

                cube[2][0][2]=cube[0][0][2];
                cube[2][1][2]=cube[0][1][2];
                cube[2][2][2]=cube[0][2][2];
                
                cube[0][0][2]=cube[4][2][0];
                cube[0][1][2]=cube[4][1][0];
                cube[0][2][2]=cube[4][0][0];

                cube[4][0][0]=cube[5][2][2];
                cube[4][1][0]=cube[5][1][2];
                cube[4][2][0]=cube[5][0][2];

                cube[5][0][2]=temp0;
                cube[5][1][2]=temp1;
                cube[5][2][2]=temp2;
            }
        }
        // cout << Rotation[i] << endl;
        // Test(cube);
    }
    // for(int i=0; i<Rotation.size(); i++)
    //     cout<<Rotation[i]<<" ";
    // cout<<endl<<endl;

    // cout << "--------------Output---------------------" << endl;
    Output(cube);
    // cout << "-----------------------------------------" << endl;
}
void Solve()
{
    // cout << "--------------Original-------------------" << endl;
    // Test(cube);
    // cout << "-----------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        int Rn;
        cin >> Rn;
        for (int j = 0; j < Rn; j++)
        {
            string temp;
            cin >> temp;
            Rotation.push_back(temp);
        }
        Rotate(cube, Rotation.size());
        Rotation.clear();
    }
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
