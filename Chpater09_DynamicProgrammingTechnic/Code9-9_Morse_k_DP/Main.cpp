/*
k번째 신호를 계산하는 알고리즘
*/
#include <iostream>
using namespace std;

// k의 최대값+100. 오버플로를 막기 위해 이보다 큰 값은 구하지 않는다.
const int M = 1000000000 + 100;
int bino[201][201];
// 필요한 모든 이항계수를 미리 계산해 둔다.
void clacBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++) {
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

// n개의 -, m개의 o로 구성된 신호 중 skip개를 건너뛰고
// 만들어지는 신호를 반환
string kth(int n, int m, int skip) {
	// n==0인 경우 나머지 부분은 전부 o일 수밖에 없다.
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