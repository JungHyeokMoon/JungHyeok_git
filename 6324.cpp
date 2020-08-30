#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<string> Urls;
void Init()
{
    cin >> n;
    Urls.resize(n);
    for (int i = 0; i < n; i++)
        cin >> Urls[i];
}
void Output(int idx, string Protocol, string Host, string Port, string Path)
{
    cout << "URL"
         << " #" << idx << endl;
    cout << "Protocol = " << Protocol << endl;
    cout << "Host     = " << Host << endl;
    cout << "Port     = " << Port << endl;
    cout << "Path     = " << Path << endl;
    cout << endl;
}
void Solve()
{
    for (int i = 0; i < n; i++)
    {
        auto ProtocolIdx = Urls[i].find("://");
        auto PortIdx = Urls[i].find(":", ProtocolIdx + 3);
        auto PathIdx = Urls[i].find("/", ProtocolIdx + 3);
        string Protocol = Urls[i].substr(0, ProtocolIdx);
        string Host;
        string Port = "<default>";
        string Path = "<default>";

        if (PortIdx == string::npos && PathIdx == string::npos)
            Host = Urls[i].substr(ProtocolIdx + 3);
        else if (PortIdx != string::npos)
        {
            Host = Urls[i].substr(ProtocolIdx + 3, PortIdx - (ProtocolIdx + 3));
            if (PathIdx != string::npos && PortIdx < PathIdx)
            {

                Port = Urls[i].substr(PortIdx + 1, PathIdx - PortIdx - 1);
                Path = Urls[i].substr(PathIdx + 1);
            }
            else if (PathIdx != string::npos && PortIdx > PathIdx)
            {
                Host = Urls[i].substr(ProtocolIdx + 3, PathIdx - (ProtocolIdx + 3));
                Path = Urls[i].substr(PathIdx + 1);
            }
            else
            {
                Port = Urls[i].substr(PortIdx + 1);
            }
        }
        else
        {
            Host = Urls[i].substr(ProtocolIdx + 3, PathIdx - (ProtocolIdx + 3));
            Path = Urls[i].substr(PathIdx + 1);
        }
        Output(i + 1, Protocol, Host, Port, Path);
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