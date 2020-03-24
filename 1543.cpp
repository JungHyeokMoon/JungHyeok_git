#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

// char doc[2500];
// char word[50];
int ret=0;
// int getlength (char * arr){
//     int i=0;
//     for(i=0; arr[i]!='\0'; i++){

//     }
//     return i;
// }
string doc,word;
void Input(){
    // gets(doc);
    // gets(word);
    getline(cin,doc);
    getline(cin,word);
}

void Solve(){
    int docleng=doc.size();
    int wordleng=word.size();
    
    for(int i=0; i<docleng; i++){
        bool flag=false;
        for(int j=0; j<wordleng; j++){   
            if(doc[i+j]!=word[j]){
                flag=true;
                break;
            }
        }
        if(!flag){
            ret++;
            i=i+wordleng-1;
        }
    }
    cout<<ret<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
