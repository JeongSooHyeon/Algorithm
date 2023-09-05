/*
메모이제이션을 이용한 이항 계수의 계산
*/

#include <iostream>
using namespace std;

int cache2[30][30];	// -1로 초기화
int bino2(int n, int r) {
	// 기저 사례 : n=r(모든 원소를 다 고르는 경우) 혹은 r=0(고를 원소가 없는 경우)
	if (r == 0 || n == r)
		return 1;

	// -1이 아니라면 한 번 계산했던 값이니 곧장 반환
	if (cache2[n][r] != -1)
		return cache2[n][r];

	// 직접 계산한 뒤 배열에 저장
	return cache2[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}

