/*
�ﰢ�� ���� �ʴ� ��� ������ Ǫ�� �޸������̼� �ڵ�
*/
#include <iostream>
#include <vector>
using namespace std;

// MAX_NUMBER : �� ĭ�� �� ������ �ִ�ġ
#define MAX_NUMBER 100
int n=5;
int triangle[100][100] = {
	{6},
	{1,2},
	{3,7,4},
	{9,4,1,7},
	{2,7,5,9,4}
};
int cache2[100][100][MAX_NUMBER * 100 + 1];
// (y,x) ��ġ���� �������� ���� ���� ���ڵ��� ���� sum�� ��
// �� �Ʒ��ٱ��� �������鼭 ���� �� �ִ� �ִ� ��θ� ��ȯ�Ѵ�.

int path2(int y, int x, int sum) {
	// ���� ��� : �� �Ʒ� �ٱ��� �������� ���
	if (y == n - 1)
		return sum + triangle[y][x];

	// �޸������̼�
	int& ret = cache2[y][x][sum];
	if (ret != -1)
		return ret;

	sum += triangle[y][x];
	return ret = max(path2(y + 1, x + 1, sum), path2(y + 1, x, sum));
}

// ���� Ž��
int pathSum(int y, int x, int sum) {
	// ���� ��� : �� �Ʒ� �ٿ� ����� ��
	if (y == n - 1) {
		return sum += triangle[y][x];
	}

	sum += triangle[y][x];

	return max(pathSum(y + 1, x, sum), pathSum(y + 1, x + 1, sum));
}

int main() {

	cout << pathSum(0, 0, 0);

	return 0;
}