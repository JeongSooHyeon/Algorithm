/*
k-1개 건너뛰고 첫 번째 신호 출력 알고리즘
*/

#include<iostream>
using namespace std;

int skip;	// skip개 건너뛰고 출력

// s: 지금까지 만든 신호 
// n: 더 필요한 -의 개수
// m: 더 필요한 o의 개수
void generate2(int n, int m, string s) {
	// 기저 사례 : skip<0
	if (skip < 0)	return;
	// 기저 사례 : n=m=0
	if (n == 0 && m == 0) {
		// 더 건너뛸 신호가 없는 경우
		if (skip == 0)	cout << s << endl;
		--skip;
		return;
	}

	if (n > 0)	generate2(n - 1, m, s + "-");
	if (m > 0)	generate2(n, m - 1, s + "0");
}

int main() {
	string str;
	skip = 3;
	generate2(2, 2, str);
}