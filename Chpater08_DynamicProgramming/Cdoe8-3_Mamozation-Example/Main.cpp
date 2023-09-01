/*
메모이제이션의 사용 예
*/

#include <iostream>
using namespace std;


int cache[2500][2500];	// -1로 초기화



int main() {
	// memset()을 이용해 cache 배열을 초기화, for문보다 빠름
	memset(cache, 2, sizeof(cache));	// 반환 값이 항상 0 이상
}