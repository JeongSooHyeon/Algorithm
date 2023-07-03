#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
// linked[i][j] = 'x' : i�� ����ġ�� j�� �ð谡 ����Ǿ� �ִ�.
// linked[i][j] = '.' : i�� ����ġ�� j�� �ð谡 ����Ǿ� ���� �ʴ�.
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.." };
// ��� �ð谡 12�ø� ����Ű�� �ִ��� Ȯ��
bool areAligned(const vector<int>& clocks) {
	for (int i = 0; i < clocks.size(); ++i) {
		if (clocks[i] != 12)
			return false;
	}
	return true;
}
// switch�� ����ġ�� ������.
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15)
				clocks[clock] = 3;
		}
	}
}
// clocks : ���� �ð���� ����
// swtch : �̹��� ���� ����ġ ��ȣ
// �� �־��� ��, ���� ����ġ���� ������ clcks�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ��ȯ
// ���� �Ұ����ϴٸ� INF �̻��� ū �� ��ȯ
int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES)	// ��� ����ġ ����
		return areAligned(clocks) ? 0 : INF;	// �����ϳ�?
	// �� ����ġ�� 0�� ������ ������ �� �� ������ �������� ��� �õ�
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	// push(clocks, swtch)�� �� �� ȣ��Ǿ����� clocks�� ������ ���� ���°� �ȴ�.
	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽� (c <= 30)
	cin >> c;

	for (int i = 0; i < c; ++i) {
		vector<int> clocks(16, -1);
		for (int j = 0; j < clocks.size(); ++j) {
			cin >> clocks[j];
		}
		cout << solve(clocks, 0) << endl;
	}
}