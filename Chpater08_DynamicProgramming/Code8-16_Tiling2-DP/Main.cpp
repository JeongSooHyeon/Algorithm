#include <iostream>
using namespace std;

const int MOD = 1000000007;
int cache[101];
// 2 * width ũ���� �簢���� ä��� ����� �� MOD�� ���� �������� ��ȯ
int tiling(int width) {
	// ���� ��� : width�� 1 ������ ��
	if (width <= 1)	return 1;

	// �޸����̼�
	int& ret = cache[width];
	if (ret != -1)	return ret;

	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int main() {
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	cout << tiling(n);


	return 0;
}