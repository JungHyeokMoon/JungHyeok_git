#include <iostream>
#include <string>
using namespace std;

int main(){
    string fan=":fan:";
    string line=fan+fan+fan;

    string input;
    cin>>input;
    
    cout<<line<<endl;
    cout<<fan<<":"<<input<<":"<<fan<<endl;
    cout<<line<<endl;
}
