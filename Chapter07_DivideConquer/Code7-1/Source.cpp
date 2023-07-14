#include <iostream>
using namespace std;

// 필수 조건 : n은 자연수
// 1 + 2 + ... +n을 반환
int fastSum(int n) {
	// 기저 사례
	if (n == 1)
		return 1;
	if (n % 2 != 0)	// 홀수일 때
		return fastSum(n - 1) + n;

	return 2 * fastSum(n / 2) + (pow(n, 2) / 4);
}

int main() {
	int n;
	cout << fastSum(10);

	return 0;
}