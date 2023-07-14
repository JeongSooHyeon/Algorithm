#include <iostream>
using namespace std;

// 정방행렬을 표현하는 SquareMatrix 클래스가 있다고 가정
class SquareMatrix;
// n*n 크기의 항등 행렬(identity matrix)을 반환하는 함수
SquareMatrix identity(int n);

// A^m 반환
SquareMatrix pow(const SquareMatrix& a, int m) {
	// 기저 사례 : a^0 = 1
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