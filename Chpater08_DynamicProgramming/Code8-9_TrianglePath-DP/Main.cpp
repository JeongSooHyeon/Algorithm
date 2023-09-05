/*
삼각형 위의 초대 경로 문제를 푸는 메모이제이션 코드
*/
#include <iostream>
#include <vector>
using namespace std;

int n = 5;
int triangle[100][100] = {
	{6},
	{1,2},
	{3,7,4},
	{9,4,1,7},
	{2,7,5,9,4}
};
int cache2[100][100];

// (y,x) 위치부터 맨 아래줄가지 내려가면서 얻을 수 있는 최대 경로의 합을 반환
int path2(int y, int x) {
	// 기저 사례 : 맨 아래 줄까지 도달했을 경우
	if (y == n - 1)
		return triangle[y][x];

	// 메모이제이션
	int& ret = cache2[y][x];
	if (ret != -1)
		return ret;

	return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}



int main() {
	memset(cache2, -1, sizeof(cache2));

	cout << path2(0, 0);

	return 0;
}