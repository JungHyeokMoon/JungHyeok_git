#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;

string str;
template<template <typename> class P = std::less >

struct compare_pair_second {

	template<class T1, class T2> bool operator()(const std::pair<T1, T2>&left, const std::pair<T1, T2>&right) {

		return P<T2>()(left.second, right.second);

	}

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<char, int> s;

	cin >> str;
	char temp;
	for (int i = 0; i < str.size(); i++) {
		temp = str[i];
		if(temp>='a' && temp<='z'){
			temp = temp - 32;
		}
		s[temp]++;
	}
	vector<pair<char, int>> v(s.begin(), s.end());
	sort(v.begin(), v.end(), compare_pair_second<std::greater>());

	if (v.size() == 1) {
		cout << v[0].first << endl;
	}
	else {
		if (v[0].second == v[1].second) {
			cout << "?" << endl;
		}
		else
			cout << v[0].first << endl;
	}
	

	return 0;
}