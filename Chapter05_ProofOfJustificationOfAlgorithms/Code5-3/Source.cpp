/*
5.3 순환 소수 찾기
*/

#include <iostream>
#include <vector>
using namespace std;

void printDecimal(int a, int b) {
	int iter = 0;
	while (a > 0) {
		// 첫 번째와 두 번째 사이에 소수점을 찍는다.
		if (iter++ == 1)
			cout << '.';
		cout << a / b;
		a = (a % b) * 10;
	}
}