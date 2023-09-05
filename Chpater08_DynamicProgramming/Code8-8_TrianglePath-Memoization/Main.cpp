/*
삼각형 위의 초대 경로 문제를 푸는 메모이제이션 코드
*/
#include <iostream>
#include <vector>
using namespace std;

// MAX_NUMBER : 한 칸에 들어갈 숫자의 최대치
#define MAX_NUMBER 100
int n=5;
int triangle[100][100] = {
	{6},
	{1,2},
	{3,7,4},
	{9,4,1,7},
	{2,7,5,9,4}
};
int cache2[100][100][MAX_NUMBER * 100 + 1];
// (y,x) 위치까지 내려오기 전에 만난 숫자들의 합이 sum일 때
// 맨 아랫줄까지 내려가면서 얻을 수 있는 최대 경로를 반환한다.

int path2(int y, int x, int sum) {
	// 기저 사례 : 맨 아래 줄까지 도달했을 경우
	if (y == n - 1)
		return sum + triangle[y][x];

	// 메모이제이션
	int& ret = cache2[y][x][sum];
	if (ret != -1)
		return ret;

	sum += triangle[y][x];
	return ret = max(path2(y + 1, x + 1, sum), path2(y + 1, x, sum));
}

// 완전 탐색
int pathSum(int y, int x, int sum) {
	// 기저 사례 : 맨 아래 줄에 닿았을 때
	if (y == n - 1) {
		return sum += triangle[y][x];
	}

	sum += triangle[y][x];

	return max(pathSum(y + 1, x, sum), pathSum(y + 1, x + 1, sum));
}

int main() {

	cout << pathSum(0, 0, 0);

	return 0;
}