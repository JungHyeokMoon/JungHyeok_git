#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
const string underline = "____";
string Arr1[5] = {"\"����Լ��� ������?\"", "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.", "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.", "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"", "��� �亯�Ͽ���."};
string Arr2[3] = {"\"����Լ��� ������?\"", "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"", "��� �亯�Ͽ���."};
void Recursion(int k)
{
    if (k == n)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cout << underline;
            }
            cout << Arr2[i] << endl;
        }
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            Recursion(k + 1);
        }
        for (int j = 0; j < k; j++)
        {
            cout << underline;
        }
        cout << Arr1[i] << endl;
    }
}
void Solve()
{
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
    Recursion(0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}