#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999;

// �� ���� : ����ġ �� �� ������
// ����ġ�� 4�� ������ ó������ ���ƿ� 0~3
// ����ġ�� ����� �ð��, ���� ����ġ
bool isFinish(vector<int>& clocks);
void push(vector<int>& clocks, int swtch);

int solve(vector<int>& clocks, int swtch) {
	// ���� ��� : ����ġ�� �� ����. 12�ø� ����Ű���� �Ǵ�
	if (swtch == 10) {	// ������ ����ġ��
		return isFinish(clocks) ? 0 : INF;
	}

	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}
int main() {
	int c;	// c <= 30
	vector<int> clocks(16, -1);
	vector<bool> swithces(10, false);
	for (int i = 0; i < 16; i++) {
		cin >> clocks[i];
	}
	solve(clocks);



	return 0;
}