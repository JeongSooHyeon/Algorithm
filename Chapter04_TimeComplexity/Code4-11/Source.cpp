/*
4.11 최대 연속 부분 구간 합 문제를 푸는 동적 계획법 알고리즘들
*/

#include <iostream>
#include <vector>
using namespace std;

const int MIN = numeric_limits<int>::min();
// a[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도 : O(n)
int fastestMaxSum(const vector<int>& a) {
	int n = a.size(), ret = MIN, psum = 0;
	for (int i = 0; i < n; ++i) {
		psum = max(psum, 0) + a[i];
		ret = max(psum, ret);
	}
	return ret;
}