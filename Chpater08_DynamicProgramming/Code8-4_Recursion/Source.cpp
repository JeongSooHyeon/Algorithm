/*
외발 뛰기 문제를 해결하는 재귀 호출 알고리즘
*/
#include <iostream>
using namespace std;


int n=7, board[100][100] = { {2,5,1,6,1,4,1},
	{6,1,1,2,2,9,3},
	{7,2,3,2,1,3,1},
	{1,1,3,1,7,1,2},
	{4,1,2,3,4,1,2},
	{3,3,1,2,3,4,1},
	{1,5,2,9,4,7,0} };

bool jump(int y, int x) {
	// 기저 사례 : 게임판 밖을 벗어난 경우
	if (y >= n || x >= n)
		return false;

	// 기저 사례 : 마지막 칸에 도착한 경우
	if (y == n - 1 && x == n - 1)
		return true;

	int jumpSize = board[y][x];

	return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

int main() {

	cout << jump(0, 0);


	return 0;
}