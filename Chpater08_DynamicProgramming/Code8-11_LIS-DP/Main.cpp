/*
�ִ� ���� �κ� ���� ������ �ذ��ϴ� ���� ��ȹ�� �˰�����(1)
*/
#include <iostream>
#include <vector>
using namespace std;


int n=5;
int cache[100], s[100];
// s[start]���� �����ϴ� ���� �κ� ���� �� �ִ� ���̸� ��ȯ
int lis2(int start) {
	int& ret = cache[start];
	if (ret != -1)
		return ret;

	// �׻� s[start]�� �ֱ� ������ ���̴� ���� 1
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (s[start] < s[next])
			ret = max(ret, lis2(next) + 1);
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

	int maxLen = 0;
	for (int begin = 0; begin < n; begin++)
		maxLen = max(maxLen, lis2(begin));

	cout << maxLen;

	return 0;
}