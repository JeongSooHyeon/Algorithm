/*
4.10 �ִ� ���� �κ� ���� �� ������ Ǫ�� ���� �˰����
*/

#include <iostream>
#include <vector>
using namespace std;

const int MIN = numeric_limits<int>::min();
// a[lo..hi]�� ���ӵ� �κ� ������ �ִ� ���� ���Ѵ�. �ð� ���⵵ : O(nlgn)
int fastMaxSum(const vector<int>& a, int lo, int hi) {
	// ���� ��� : ������ ���̰� 1�� ���
	if (lo == hi)
		return a[lo];

	// �迭�� a[lo..mid], a[mid+1..hi]�� �� �������� ������.
	int mid = (lo + hi) / 2;

	// �� �κп� ��� ���� �ִ� �ִ� �� ������ ã�´�. �� ������
	// a[i..mid]�� a[mid+1..j]�� ���¸� ���� ������ ������ �̷����
	
	// a[i..mid]���¸� ���� �ִ� ������ ã�´�.
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; --i) {
		sum += a[i];
		left = max(left, sum);
	}
	// a[mid+1..j] ���¸� ���� �ִ� ������ ã�´�.
	sum = 0;
	for (int j = mid + 1; j <= hi; ++j) {
		sum += a[j];
		right = max(right, sum);
	}

	// �ִ� ������ �� ���� �� �ϳ����� ���� �ִ� ����� ���� ��� ȣ��� ã�´�.
	int single = max(fastMaxSum(a, lo, mid), fastMaxSum(a, mid + 1, hi));

	// �� ��� �� �ִ�ġ�� ��ȯ
	return max(left + right, single);
}