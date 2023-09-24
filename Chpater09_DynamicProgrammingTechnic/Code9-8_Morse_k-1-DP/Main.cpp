/*
k-1�� �ǳʶٰ� ù ��° ��ȣ ��� �˰���
*/

#include<iostream>
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

int skip;
// skip���� �ǳʶٰ� ���
void generate3(int n, int m, string s) {
	// ���� ��� : skip<0
	if (skip < 0)	return;
	// ���� ��� : n=m=0
	if (n == 0 && m == 0) {
		// �� �ǳʶ� ��ȣ�� ���� ���
		if (skip == 0)	cout << s << endl;
		--skip;
		return;
	}

	// 
	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}

	if (n > 0)	generate3(n - 1, m, s + "-");
	if (m > 0)	generate3(n, m - 1, s + "0");
}

int main() {
	string str;
	skip = 5;
	clacBino();
	generate3(2, 2, str);
}