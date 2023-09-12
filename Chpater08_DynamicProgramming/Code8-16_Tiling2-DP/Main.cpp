#include <iostream>
using namespace std;

const int MOD = 1000000007;
int cache[101];
// 2 * width 크기의 사각형을 채우는 방법의 수 MOD로 나눈 나머지를 반환
int tiling(int width) {
	// 기저 사례 : width가 1 이하일 때
	if (width <= 1)	return 1;

	// 메모제이션
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