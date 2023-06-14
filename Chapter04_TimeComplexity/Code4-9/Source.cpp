/*
4.9 �ִ� ���� �κ� ���� �� ������ Ǫ�� ������ �˰����
*/

#include <iostream>
#include <vector>
using namespace std;

const int MIN = numeric_limits<int>::min();
// a[]�� ���ӵ� �κ� ������ �ִ� ���� ���Ѵ�. �ð� ���⵵:O(N^3)
int inefficientMaxSum(vector<int>& a) {
	int n = a.size(), ret = MIN;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j) {
			// ���� a[i..j]�� ��
			int sum = 0;
			for (int k = i; k <= j; ++k)
				sum += a[k];
			ret = max(ret, sum);
		}
	return ret;
}

// a[]�� ���ӵ� �κ� ������ �ִ� ���� ���Ѵ�. �ð� ���⵵ : O(N^2)
int betterMaxSum(const vector<int>& a) {
	int n = a.size(), ret = MIN;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			// ���� a[i..j]�� ��
			sum += a[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}