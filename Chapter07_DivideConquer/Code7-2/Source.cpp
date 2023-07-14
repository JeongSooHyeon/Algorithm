#include <iostream>
using namespace std;

// ��������� ǥ���ϴ� SquareMatrix Ŭ������ �ִٰ� ����
class SquareMatrix;
// n*n ũ���� �׵� ���(identity matrix)�� ��ȯ�ϴ� �Լ�
SquareMatrix identity(int n);

// A^m ��ȯ
SquareMatrix pow(const SquareMatrix& a, int m) {
	// ���� ��� : a^0 = 1
	if (m == 0) return identity(a.size());
	if (m % 2 > 0) 
		return pow(a, m - 1) * a;

	SquareMatrix half = pow(a, m / 2);
	// a^m = (a^(m/2)) * (a^(m/2))
	return half * half;
}

int main() {

	return 0;
}