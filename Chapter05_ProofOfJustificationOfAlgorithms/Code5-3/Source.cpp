/*
5.3 ��ȯ �Ҽ� ã��
*/

#include <iostream>
#include <vector>
using namespace std;

void printDecimal(int a, int b) {
	int iter = 0;
	while (a > 0) {
		// ù ��°�� �� ��° ���̿� �Ҽ����� ��´�.
		if (iter++ == 1)
			cout << '.';
		cout << a / b;
		a = (a % b) * 10;
	}
}