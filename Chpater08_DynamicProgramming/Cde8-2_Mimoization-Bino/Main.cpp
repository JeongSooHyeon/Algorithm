/*
�޸������̼��� �̿��� ���� ����� ���
*/

#include <iostream>
using namespace std;

int cache2[30][30];	// -1�� �ʱ�ȭ
int bino2(int n, int r) {
	// ���� ��� : n=r(��� ���Ҹ� �� ���� ���) Ȥ�� r=0(�� ���Ұ� ���� ���)
	if (r == 0 || n == r)
		return 1;

	// -1�� �ƴ϶�� �� �� ����ߴ� ���̴� ���� ��ȯ
	if (cache2[n][r] != -1)
		return cache2[n][r];

	// ���� ����� �� �迭�� ����
	return cache2[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}

