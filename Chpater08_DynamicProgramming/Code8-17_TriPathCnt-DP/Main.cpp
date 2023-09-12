#include <iostream>
using namespace std;

int n = 4;

int triangle[100][100] = {
	{9},
	{5,7},
	{1,3,2},
	{3,5,5,6}
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

int countCache[100][100];
// (y,x)���� �����ؼ� �� �Ʒ��ٱ��� �������� ��� �� �ִ� ����� ���� ��ȯ
int count(int y, int x) {
	// ���� ��� : �� �Ʒ��ٿ� ������ ���
	if (y == n - 1)	return 1;

	// �޸����̼�
	int& ret = countCache[y][x];
	if (ret != -1)	return ret;

	ret = 0;
	if (path2(y + 1, x + 1) >= path2(y + 1, x))
		ret += count(y + 1, x + 1);
	if (path2(y + 1, x + 1) <= path2(y + 1, x))
		ret += count(y + 1, x);

	return ret;
}



int main() {
	memset(countCache, -1, sizeof(countCache));
	memset(cache2, -1, sizeof(cache2));

	cout << count(0, 0);


	return 0;
}