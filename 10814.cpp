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
		return (u.age < v.age) || (u.age == v.age&&u.join < v.join); //���ٽ��̿�.. �߸𸣰���
	});

	for (int i = 0; i < n; i++) {
		cout << arr[i].age <<" "<<arr[i].name << '\n';//endl�̶� \n�̶� �ð����̰��ִ� �̰� ��������
	}

	return 0;
}