/*
4.4 선형 시간에 이동 평균 구하기
*/

#include <iostream>
#include <vector>
using namespace std;

// 길이가 n인 실수 배열 a가 주어질 때, 각 위치에서의 m-이동 평균 값을 구한다.
vector<double> movingAverage2(const vector<double>& a, int m) {
	vector<double> ret;
	int n = a.size();
	double partialSum = 0;
	for (int i = 0; i < m-1; ++i) {	// 0~m-2(m-1개)
		partialSum += a[i];
	}

	for (int j = m-1; j < n; ++j) {
		partialSum += a[j];
		ret.push_back(partialSum / m);
		partialSum -= a[j - m + 1];
	}
	return ret;
}