#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(true){
        getline(cin, s);
        if(s=="") //�̰ž����� ����ʰ���� �����������δ°�
            break;
        cout<<s<<endl;
    }

    return 0;
}