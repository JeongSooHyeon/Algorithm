#include <iostream>
using namespace std;

int n = 7, board[100][100] = {
	{2,5,1,6,1,4,1},
	{6,1,1,2,2,9,3},
	{7,2,3,2,1,3,1},
	{1,1,3,1,7,1,2},
	{4,1,2,3,4,1,3},	// �ٲٱ�
	{3,3,1,2,3,4,1},
	{1,5,2,9,4,7,0} };
int cache[100][100];

int jumpGame(int y, int x) {
	// ���� ��� : ���� ��Ż
	if (y >= n || x >= n) {
		return 0;
	}
	// ���� ��� : ����
	if (y == n - 1 && x == n - 1) {
		return 1;
	}

	// �޸������̼�
	int ret = cache[y][x];
	if (ret != -1)	return ret;

	// ���
	int jumpSize = board[y][x];
	ret = jumpGame(y + jumpSize, x) ||
		jumpGame(y, x + jumpSize);

}
int main() {
	memset(cache, -1, sizeof(cache));

	cout << jumpGame(0, 0);

	return 0;
}