/*
4.11 �ִ� ���� �κ� ���� �� ������ Ǫ�� ���� ��ȹ�� �˰����
*/

#include <iostream>
#include <vector>
using namespace std;

const int MIN = numeric_limits<int>::min();
// a[]�� ���ӵ� �κ� ������ �ִ� ���� ���Ѵ�. �ð� ���⵵ : O(n)
int fastestMaxSum(const vector<int>& a) {
	int n = a.size(), ret = MIN, psum = 0;
	for (int i = 0; i < n; ++i) {
		psum = max(psum, 0) + a[i];
		ret = max(psum, ret);
	}
	return ret;
}