/*
k��° ��ȣ�� ����ϴ� �˰���
*/
#include <iostream>
using namespace std;

// k�� �ִ밪+100. �����÷θ� ���� ���� �̺��� ū ���� ������ �ʴ´�.
const int M = 1000000000 + 100;
int bino[201][201];
// �ʿ��� ��� ���װ���� �̸� ����� �д�.
void clacBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++) {
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

// n���� -, m���� o�� ������ ��ȣ �� skip���� �ǳʶٰ�
// ��������� ��ȣ�� ��ȯ
string kth(int n, int m, int skip) {
	// n==0�� ��� ������ �κ��� ���� o�� ���ۿ� ����.
	if (n == 0)	return string(m, 'o');

	if (skip < bino[n + m - 1][n - 1])
		return "-" + kth(n - 1, m, skip);

	return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

int main() {
	string str;
	clacBino();
	cout << kth(2, 2, 5);
}