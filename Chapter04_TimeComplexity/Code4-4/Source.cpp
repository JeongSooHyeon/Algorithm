/*
4.4 ���� �ð��� �̵� ��� ���ϱ�
*/

#include <iostream>
#include <vector>
using namespace std;

// ���̰� n�� �Ǽ� �迭 a�� �־��� ��, �� ��ġ������ m-�̵� ��� ���� ���Ѵ�.
vector<double> movingAverage2(const vector<double>& a, int m) {
	vector<double> ret;
	int n = a.size();
	double partialSum = 0;
	for (int i = 0; i < m-1; ++i) {	// 0~m-2(m-1��)
		partialSum += a[i];
	}

	for (int j = m-1; j < n; ++j) {
		partialSum += a[j];
		ret.push_back(partialSum / m);
		partialSum -= a[j - m + 1];
	}
	return ret;
}