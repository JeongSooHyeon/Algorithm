/*
�޸������̼��� ��� ��
*/

#include <iostream>
using namespace std;


int cache2[2500][2500];	// -1�� �ʱ�ȭ

// a�� b�� ���� [0, 2500) ���� ���� ����
// ��ȯ ���� �׻� int �� �ȿ� ���� ���� �ƴ� ����
int someObscureFunction(int a, int b) {
	// ���� ��� : �Է��� ������ ��� ��� ��
	if (...)
		return ...;

	// (a,b)�� ���� ���� ���� ���� ������ ���� ��ȯ
	int& ret = cache2[a][b];	// ������
	if (ret != -1)
		return ret;

	// ���⿡�� ���� ���
	...

		return ret;
}

int main() {
	// memset()�� �̿��� cache �迭�� �ʱ�ȭ, for������ ����
	memset(cache2, -1, sizeof(cache2));	// ��ȯ ���� �׻� 0 �̻�
}