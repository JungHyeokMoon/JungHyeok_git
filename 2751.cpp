// #include <iostream>
// #include <algorithm>
// #include <string>
// using namespace std;

// int main() {
// 	int n;
// 	scanf("%d", &n);
	
// 	int *arr = new int[n];

// 	for (int i = 0; i < n; i++)
// 		scanf("%d", &arr[i]);

// 	sort(arr, arr + n);

// 	for (int i = 0; i < n; i++)
// 		printf("%d\n", arr[i]);


// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<int> A;
void Init(){
	cin>>n;
	A.resize(n);
	for(int i=0; i<n; i++)
		cin>>A[i];
	
}
void Merge(int l, int r){
	// cout<<"Merge l: "<<l<<" r: "<<r<<endl;
	vector<int> temp(r-l);
	int mid=(l+r)/2;
	int k=0; //temp 인덱스
	int i=l;
	int j=mid;
	while(i<mid && j<r){
		if(A[i]>=A[j])
			temp[k++]=A[j++];
		else
			temp[k++]=A[i++];
	}

	while(i<mid)
		temp[k++]=A[i++];
	while(j<r)
		temp[k++]=A[j++];
	
	k=0;
	for(int i=l; i<r; i++)
		A[i]=temp[k++];
	
}
void MergeSort(int l, int r){
	if(r-l==1)
		return ;
	if(r-l==2){
		if(A[l]>A[l+1]){
			swap(A[l],A[l+1]);
			// cout<<"l: "<<l<<" r: "<<r<<endl;
			// for(int i=l; i<r; i++)
			// 	cout<<A[i]<<" ";
			// cout<<endl;
			return;
		}
	}
	int mid=(l+r)/2;
	MergeSort(l,mid);
	MergeSort(mid,r);
	Merge(l,r);
}
void Output(){
	// cout<<"------------------Output-------------------"<<endl;
	for(auto i : A)
	 	cout<<i<<" ";
	cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	Init();
	MergeSort(0,n);
	Output();
	return 0;
}