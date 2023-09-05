/*
�ﰢ�� ���� �ʴ� ��� ������ Ǫ�� �޸������̼� �ڵ�
*/
#include <iostream>
#include <vector>
using namespace std;

int n = 5;
int triangle[100][100] = {
	{6},
	{1,2},
	{3,7,4},
	{9,4,1,7},
	{2,7,5,9,4}
};
int cache2[100][100];

// (y,x) ��ġ���� �� �Ʒ��ٰ��� �������鼭 ���� �� �ִ� �ִ� ����� ���� ��ȯ
int path2(int y, int x) {
	// ���� ��� : �� �Ʒ� �ٱ��� �������� ���
	if (y == n - 1)
		return triangle[y][x];

	// �޸������̼�
	int& ret = cache2[y][x];
	if (ret != -1)
		return ret;

	return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}



int main() {
	memset(cache2, -1, sizeof(cache2));

	cout << path2(0, 0);

	return 0;
}