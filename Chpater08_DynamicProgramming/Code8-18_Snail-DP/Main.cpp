#include <iostream>
using namespace std;
#define MAX_N 100
int n=1, m=1;
int cache[MAX_N][2 * MAX_N + 1];
// �����̰� days�� ���� climbed ���͸� ���ö� �Դٰ� �� ��,
// m�� ������ n���͸� ���ö� �� �ִ� ����� ��
int climb(int days, int climbed) {
	// ���� ��� : m���� ��� ���� ���
	if (days == m)
		return climbed >= n ? 1 : 0;

	// �޸����̼�
	int& ret = cache[days][climbed];
	if (ret != -1)
		return ret;

	return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}

int main() {
	memset(cache, -1, sizeof(cache));
	
	cout << climb(0,0);
}