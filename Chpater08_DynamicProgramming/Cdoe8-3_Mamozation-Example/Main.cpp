/*
메모이제이션의 사용 예
*/

#include <iostream>
using namespace std;


int cache[2500][2500];	// -1로 초기화

// a와 b는 각각 [0, 2500) 구간 안의 정수
// 반환 값은 항상 int 형 안에 들어가는 음이 아닌 정수
int someObscureFunction(int a, int b) {
	// 기저 사례 : 입력이 범위를 벗어난 경우 등
	if (...)
		return ...;

	// (a,b)에 대한 답을 구한 적이 있으면 곧장 반환
	int& ret = cache[a][b];	// 참조형
	if (ret != -1)
		return ret;

	// 여기에서 답을 계싼
	...

		return ret;
}

int main() {
	// memset()을 이용해 cache 배열을 초기화, for문보다 빠름
	memset(cache, -1, sizeof(cache));	// 반환 값이 항상 0 이상
}