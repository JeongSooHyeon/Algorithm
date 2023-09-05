/*
최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘(1)
*/
#include <iostream>
#include <vector>
using namespace std;


int n=5;
int cache[100], s[100];
// s[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환
int lis2(int start) {
	int& ret = cache[start];
	if (ret != -1)
		return ret;

	// 항상 s[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (s[start] < s[next])
			ret = max(ret, lis2(next) + 1);
	}
	return ret;
}

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(2);
	a.push_back(4);

	memset(cache, -1, sizeof(cache));
	s[0] = 1;
	s[1] = 3;
	s[2] = 4;
	s[3] = 2;
	s[4] = 4;

	cout << lis2(0);


	return 0;
}