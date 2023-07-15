#include <iostream>
#include <vector>
using namespace std;

// num[]�� �ڸ��� �ø��� ó��
void normalize(vector<int>& num) {
	num.push_back(0);
	// �ڸ��� �ø� ó��
	for (int i = 0; i + 1 < num.size(); ++i) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

// �� �� �ڿ����� ���� ��ȯ
// �� �迭���� �� ���� �ڸ����� 1�� �ڸ��������� ������ ����Ǿ� �ִ�.
// �� : multiply({3,2,1}, {6,5,4}) = 123 * 456 = 56088 = {8,8,0,6,5}
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			c[i + j] += a[i] * b[j];
		}
	}	
	normalize(c);
	return c;
}

int main() {
	vector<int> a;	// 123
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	vector<int> b;	//456
	b.push_back(6);
	b.push_back(5);
	b.push_back(4);

	vector<int> c = multiply(a, b);
	for (int i = 0; i < c.size(); ++i)
		cout << c[i];
}