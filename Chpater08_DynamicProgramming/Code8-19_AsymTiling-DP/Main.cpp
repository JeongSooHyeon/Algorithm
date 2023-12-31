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

// 2*width 크기의 사각형을 채우는 비대칭 방법의 수를 반환
int asymmetric(int width) {
	if (width % 2 == 1)	// 홀수
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	int ret = tiling(width);
	ret = (ret - tiling(width / 2) + MOD) % MOD;
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
	return ret;
}

int main() {
	int c;	// 테스트 케이스 수, 1<=c<=50
	cin >> c;
	int n;
	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		cout << asymmetric(n) << endl;
	}
	return 0;
}