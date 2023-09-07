/*
�ִ� ���� �κ� ���� ������ �ذ��ϴ� ���� ��ȹ�� �˰���(2)
*/
#include <iostream>
#include <vector>
using namespace std;


int n = 5;
int cache[101], s[100];
// s[start]���� �����ϴ� ���� �κ� ���� �� �ִ� ���̸� ��ȯ
int lis3(int start) {
	int& ret = cache[start + 1];	// start=-1�� �־��� �� �ֱ� ����
	if (ret != -1)
		return ret;

	// �׻� s[start]�� �ֱ� ������ ���̴� ���� 1
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || s[start] < s[next])
			ret = max(ret, lis3(next) + 1);
	}
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	s[0] = 1;
	s[1] = 3;
	s[2] = 4;
	s[3] = 2;
	s[4] = 4;

	cout << lis3(-1) - 1;


	return 0;
}