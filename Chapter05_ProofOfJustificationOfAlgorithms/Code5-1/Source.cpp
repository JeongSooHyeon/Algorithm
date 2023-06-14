/*
5.1 ���� Ž��
*/

#include <iostream>
#include <vector>
using namespace std;

// �ʼ� ���� : a�� ������������ ���ĵǾ� �ִ�.
// ��� : a[i-1] < x <= a[i]�� i�� ��ȯ�Ѵ�.
// �̶� a[-1] = ���� ���Ѵ�, a[n] = ���� ���Ѵ��� ����
int binsearch(const vector<int>& a, int x) {
	int n = a.size();
	int lo = -1, hi = n;
	// �ݺ��� �Һ��� 1 : lo < hi
	// �ݺ��� �Һ��� 2 : a[lo] <= a[hi]
	// (*) �Һ����� ���⼭ �����ؾ� �Ѵ�.
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (a[mid] < x)
			lo = mid;
		else
			hi = mid;
		// (**) �Һ����� ���⼭�� �����ؾ� �Ѵ�.
	}
	return hi;
}