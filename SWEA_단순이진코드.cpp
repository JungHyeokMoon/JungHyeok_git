#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
vector<vector<int>> arr;
string code[10]={"0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011"};
int RetunNum(string str){
	for(int i=0; i<10; i++){
		if(str==code[i]){
			return i;
		}
	}
	return -1;
}
int Check(vector<int> v){
	vector<int> Num;
	string temp="";
	int sum=0;
	int pushnum;
	for(int i=0; i<v.size(); ++i){
		if(i!=0 && i%7==0){
			pushnum=RetunNum(temp);
			sum+=pushnum;
			Num.push_back(pushnum);
			temp.clear();
		}
		temp+=char(v[i]+'0');
	}
	pushnum=RetunNum(temp);
	sum+=pushnum;
	Num.push_back(pushnum);
	// cout<<endl;
	// for(int i=0; i<Num.size(); i++){
	// 	cout<<Num[i]<<" ";
	// }
	int oddnum=0;
	int evenum=0;
	int paritynum=0;
	for(int i=0; i<8; i++){
		if(i%2==0){
			oddnum+=Num[i];
		}
		else {
			evenum+=Num[i];
		}
	}
	paritynum=(oddnum*3)+evenum;
	if(paritynum%10==0){
		return sum;
	}
	else{
		return -1;
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n>>m;
		if(m<56){
			cout<<"#"<<test_case<<" 0"<<endl;
			continue;
		}
		arr.clear();
		arr.resize(n,vector<int>(m));
		for(int i=0; i<n; i++){
			string temp;
			cin>>temp;
			for(int j=0; j<m; j++){
				arr[i][j]=temp[j]-'0';
			}
		}
		bool flag=false;
		int paritycode=0;
		for(int i=0; i<n; i++){
			for(int j=m-1; j>=0; j--){
				if(arr[i][j]==1){
					vector<int> temp=vector<int>(arr[i].begin()+j-56+1, arr[i].begin()+j+1);
					// for(int i=0; i<temp.size(); i++){
					// 	if(i%7==0)cout<<" ";
					// 	cout<<temp[i];
					// }
					// cout<<endl;
					paritycode=Check(temp);
					flag=true;
					break;
				}
			}
			if(flag)break;
		}
		if(paritycode!=-1){
			cout<<"#"<<test_case<<" "<<paritycode<<endl;
		}
		else{
			cout<<"#"<<test_case<<" "<<0<<endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}