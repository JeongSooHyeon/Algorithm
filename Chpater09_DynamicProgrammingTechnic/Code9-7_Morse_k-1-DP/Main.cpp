/*
k-1�� �ǳʶٰ� ù ��° ��ȣ ��� �˰���
*/

#include<iostream>
using namespace std;

int skip;	// skip�� �ǳʶٰ� ���

// s: ���ݱ��� ���� ��ȣ 
// n: �� �ʿ��� -�� ����
// m: �� �ʿ��� o�� ����
void generate2(int n, int m, string s) {
	// ���� ��� : skip<0
	if (skip < 0)	return;
	// ���� ��� : n=m=0
	if (n == 0 && m == 0) {
		// �� �ǳʶ� ��ȣ�� ���� ���
		if (skip == 0)	cout << s << endl;
		--skip;
		return;
	}

	if (n > 0)	generate2(n - 1, m, s + "-");
	if (m > 0)	generate2(n, m - 1, s + "0");
}

int main() {
	string str;
	skip = 3;
	generate2(2, 2, str);
}