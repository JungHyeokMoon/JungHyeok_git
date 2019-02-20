#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

struct Student {
	string name;
	int kor;
	int eng;
	int math;

};
bool cmp(const Student &u, const Student &v) {
	return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name);
}

int main() {
	int n;
	scanf("%d", &n);

	Student *arr = new Student[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i].name;
		scanf("%d %d %d", &arr[i].kor, &arr[i].eng, &arr[i].math);
	}
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].name<<'\n';
	}

	return 0;
	
}