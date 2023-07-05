#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999;

// 한 조각 : 스위치 몇 번 누를지
// 스위치는 4번 돌리면 처음으로 돌아옴 0~3
// 스위치에 연결된 시계들, 누른 스위치
bool isFinish(vector<int>& clocks);
void push(vector<int>& clocks, int swtch);

int solve(vector<int>& clocks, int swtch) {
	// 기저 사례 : 스위치를 다 누름. 12시를 가리키는지 판단
	if (swtch == 10) {	// 마지막 스위치야
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