/*
최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘(2)
*/
#include <iostream>
#include <vector>
using namespace std;


int n = 5;
int cache[101], s[100];
// s[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환
int lis3(int start) {
	int& ret = cache[start + 1];	// start=-1이 주어질 수 있기 때문
	if (ret != -1)
		return ret;

	// 항상 s[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || s[start] < s[next])
			ret = max(ret, lis3(next) + 1);
	}
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	s[0] = 1;
	s[1] = 3;
	s[2] = 4;
	s[3] = 2;
	s[4] = 4;

	cout << lis3(-1) - 1;


	return 0;
}