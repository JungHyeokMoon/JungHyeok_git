#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Person {
	int age;
	string name;
};

bool cmp(const Person &u, const Person &v) {
	return u.age < v.age;
}
int main() {
	int n;
	scanf("%d", &n);
	Person *arr = new Person[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i].age >> arr[i].name;
	}

	stable_sort(arr, arr + n,cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].age <<" "<<arr[i].name << '\n';
	}

	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Person {
	int age;
	string name;
	int join;
};

bool cmp(const Person &u, const Person &v) {
	return u.age < v.age;
}
int main() {
	int n;
	scanf("%d", &n);
	Person *arr = new Person[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i].age >> arr[i].name;
		arr[i].join = i;
	}

	sort(arr, arr + n, [](Person &u, Person&v) {
		return (u.age < v.age) || (u.age == v.age&&u.join < v.join); //람다식이용.. 잘모르겠음
	});

	for (int i = 0; i < n; i++) {
		cout << arr[i].age <<" "<<arr[i].name << '\n';//endl이랑 \n이랑 시간차이가있다 이거 유의하자
	}

	return 0;
}