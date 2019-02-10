#include <iostream>
#include <string>
#include <string>
using namespace std;

int main(){
	string s;

	while (getline(cin, s)) {

		int upper_case = 0;
		int lower_case = 0;
		int num = 0;
		int space = 0;

		for (char x:s) { //스트링에있는 모든 문자에대하여
			
			if ('0' <= x && x <= '9')
				num++;
			else if ('A' <= x && x <= 'Z')
				upper_case++;
			else if ('a' <= x && x <= 'z')
				lower_case++;
			else if(x==' ')
				space++;
		}

		printf("%d %d %d %d", lower_case, upper_case, num, space);

		printf("\n");
	}
	return 0;

}