/*
��� �� ��ȣ�� ����� ���� Ž�� �˰���
*/

#include<iostream>
using namespace std;


// s: ���ݱ��� ���� ��ȣ 
// n: �� �ʿ��� -�� ����
// m: �� �ʿ��� o�� ����
void generate(int n, int m, string s) {
	// ���� ��� : n=m=0
	if (n == 0 && m == 0) {
		cout << s << endl;
		return;
	}

	if (n > 0)	generate(n - 1, m, s + "-");
 	if (m > 0) generate(n, m - 1, s + "0");
}

int main() {
	string str;
	generate(2, 2, str);
}