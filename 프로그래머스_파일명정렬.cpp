#include <bits/stdc++.h>
using namespace std;

class fileName{
    public:
        string HEAD;
        string NUMBER;
        string TAIL;
        string TotalString;
        fileName(string H,string N, string T):HEAD(H),NUMBER(N),TAIL(T){
            TotalString=HEAD+NUMBER+TAIL;
        };
};
bool Compare(fileName a, fileName b){
    string headUpperA;
    string headUpperB;
    
    for(int i=0 ; i<a.HEAD.size(); i++){
        if('a'<=a.HEAD[i] && a.HEAD[i]<='z')
            headUpperA.push_back(toupper(a.HEAD[i]));
        else
            headUpperA.push_back(a.HEAD[i]);
    }
    for(int i=0 ; i<b.HEAD.size(); i++){
        if('a'<=b.HEAD[i] && b.HEAD[i]<='z')
            headUpperB.push_back(toupper(b.HEAD[i]));
        else
            headUpperB.push_back(b.HEAD[i]);
    }
    if(headUpperA<headUpperB)
        return true;
    else if(headUpperA==headUpperB){
        int numA=stoi(a.NUMBER);
        int numB=stoi(b.NUMBER);
        if(numA<numB)
            return true;
        else
            return false;
    }else{
        return false;
    }
    
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    int length=files.size();

    vector<fileName> fileNames;

    for(int i=0; i<length; i++){
        int fileLength=files[i].size();
        int j=0;
        string head;
        string number;
        string tail;

        for(j=0; j<fileLength; j++){
            if('0'<=files[i][j] && files[i][j]<='9')
                break;
        }
        head=files[i].substr(0,j);
        int k=j;
        for(; j<fileLength; j++){
            if(!('0'<=files[i][j] && files[i][j]<='9'))
                break;
        }
        number=files[i].substr(k,j-k);
        tail=files[i].substr(j);

        fileName fTemp=fileName(head,number,tail);
        fileNames.push_back(fTemp);
    }

    
    stable_sort(fileNames.begin(),fileNames.end(),Compare);
    for(auto obj : fileNames)
        answer.push_back(obj.TotalString);
    return answer;
}

int main(){
    vector<string> files;
    
    // files.push_back("img12.png");
    // files.push_back("img10.png");
    // files.push_back("img02.png");
    // files.push_back("img1.png");
    // files.push_back("IMG01.GIF");
    // files.push_back("img2.JPG");

    files.push_back("F-5 Freedom Fighter");
    files.push_back("B-50 Superfortress");
    files.push_back("A-10 Thunderbolt II");
    files.push_back("F-14 Tomcat");
    
    vector<string> Answer=solution(files);
    
    for(auto str :Answer)
        cout<<str<<" ";
    return 0;
}