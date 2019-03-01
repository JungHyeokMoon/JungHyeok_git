#include <iostream>
using namespace std;
int main() {
	struct Date {
		int year, month, day;
		Date(int y=0, int m=0, int d=0) :year(y), month(m), day(d){}
	};

	int year1, month1, day1;
	int year2, month2, day2;
	scanf("%d %d %d", &year1, &month1, &day1);
	scanf("%d %d %d", &year2, &month2, &day2);

	Date born(year1, month1, day1);
	Date now(year2, month2, day2);

	int diff = now.year - born.year;

	if (born.year == now.year)
		printf("0\n"); //생후 1년안됐을경우
	else {
		if (born.month == now.month) {
			if (born.day > now.day) //생일이 안지났을경우 -1
				printf("%d\n", diff - 1);
			else
				printf("%d\n", diff);
		}
		else if (born.month < now.month) {//생일이지난경우
			printf("%d\n", diff);
		}
		else
			printf("%d\n", diff - 1);
	}
	printf("%d\n", diff + 1);
	printf("%d\n", diff);
	return 0;

}