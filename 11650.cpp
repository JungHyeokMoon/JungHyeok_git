#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Point {
	int x, y;
	
};

bool cmp(const Point &u, const Point &v) {
	if(u.x<v.x){
		return true;
	}
	else if (u.x == v.x) {
		return u.y < v.y;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	Point * arr = new Point[n];

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x ,  arr[i].y);

	}

	return 0;
}
