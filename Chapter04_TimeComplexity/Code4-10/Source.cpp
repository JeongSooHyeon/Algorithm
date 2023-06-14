/*
4.10 최대 연속 부분 구간 합 문제를 푸는 정복 알고리즘들
*/

#include <iostream>
#include <vector>
using namespace std;

const int MIN = numeric_limits<int>::min();
// a[lo..hi]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도 : O(nlgn)
int fastMaxSum(const vector<int>& a, int lo, int hi) {
	// 기저 사례 : 구간의 길이가 1일 경우
	if (lo == hi)
		return a[lo];

	// 배열을 a[lo..mid], a[mid+1..hi]의 두 조각으로 나눈다.
	int mid = (lo + hi) / 2;

	// 두 부분에 모두 걸쳐 있는 최대 합 구간을 찾는다. 이 구간은
	// a[i..mid]와 a[mid+1..j]의 형태를 갖는 구간의 합으로 이루어짐
	
	// a[i..mid]형태를 갖는 최대 구간을 찾는다.
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; --i) {
		sum += a[i];
		left = max(left, sum);
	}
	// a[mid+1..j] 형태를 갖는 최대 구간을 찾는다.
	sum = 0;
	for (int j = mid + 1; j <= hi; ++j) {
		sum += a[j];
		right = max(right, sum);
	}

	// 최대 구간이 두 조각 중 하나에만 속해 있는 경우의 답을 재귀 호출로 찾는다.
	int single = max(fastMaxSum(a, lo, mid), fastMaxSum(a, mid + 1, hi));

	// 두 경우 중 최대치를 반환
	return max(left + right, single);
}