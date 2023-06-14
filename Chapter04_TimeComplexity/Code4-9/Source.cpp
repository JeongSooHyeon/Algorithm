/*
4.9 최대 연속 부분 구간 합 문제를 푸는 무식한 알고리즘들
*/

#include <iostream>
#include <vector>
using namespace std;

const int MIN = numeric_limits<int>::min();
// a[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도:O(N^3)
int inefficientMaxSum(vector<int>& a) {
	int n = a.size(), ret = MIN;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j) {
			// 구간 a[i..j]의 합
			int sum = 0;
			for (int k = i; k <= j; ++k)
				sum += a[k];
			ret = max(ret, sum);
		}
	return ret;
}

// a[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도 : O(N^2)
int betterMaxSum(const vector<int>& a) {
	int n = a.size(), ret = MIN;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			// 구간 a[i..j]의 합
			sum += a[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}