#include <iostream>
using namespace std;

// �ʼ� ���� : n�� �ڿ���
// 1 + 2 + ... +n�� ��ȯ
int fastSum(int n) {
	// ���� ���
	if (n == 1)
		return 1;
	if (n % 2 != 0)	// Ȧ���� ��
		return fastSum(n - 1) + n;

	return 2 * fastSum(n / 2) + (pow(n, 2) / 4);
}

int main() {
	int n;
	cout << fastSum(10);

	return 0;
}