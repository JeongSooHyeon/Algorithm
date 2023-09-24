/*
k-1개 건너뛰고 첫 번째 신호 출력 알고리즘
*/

#include<iostream>
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

int skip;
// skip개를 건너뛰고 출력
void generate3(int n, int m, string s) {
	// 기저 사례 : skip<0
	if (skip < 0)	return;
	// 기저 사례 : n=m=0
	if (n == 0 && m == 0) {
		// 더 건너뛸 신호가 없는 경우
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