#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

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



int main() {
	int c;	// 테스트 케이스 (c <= 30)
	cin >> c;

	for (int i = 0; i < c; ++i) {
		vector<int> clocks(16, -1);
		for (int j = 0; j < clocks.size(); ++j) {
			cin >> clocks[j];
		}

	}
}