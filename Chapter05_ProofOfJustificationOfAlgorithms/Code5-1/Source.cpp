/*
5.1 이진 탐색
*/

#include <iostream>
#include <vector>
using namespace std;

// 필수 조건 : a는 오름차순으로 정렬되어 있다.
// 결과 : a[i-1] < x <= a[i]인 i를 반환한다.
// 이때 a[-1] = 음의 무한대, a[n] = 양의 무한대라고 가정
int binsearch(const vector<int>& a, int x) {
	int n = a.size();
	int lo = -1, hi = n;
	// 반복문 불변식 1 : lo < hi
	// 반복문 불변식 2 : a[lo] <= a[hi]
	// (*) 불변식은 여기서 성립해야 한다.
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (a[mid] < x)
			lo = mid;
		else
			hi = mid;
		// (**) 불변식은 여기서도 성립해야 한다.
	}
	return hi;
}