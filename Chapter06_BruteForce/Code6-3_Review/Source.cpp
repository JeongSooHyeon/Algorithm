#include <iostream>
#include <vector>
using namespace std;

int coordinate[8][2] = {
	{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}
};

bool hasWord(char alphabet[5][5], int y, int x, string word) {
	// 기저 사례 : 시작 위치가 범위 밖이면 실패
	if (y >= 5 || y < 0 || x >= 5 || x < 0)
		return false;
	// 기저 사례 : 첫 글자가 아닌 경우 실패
	if (alphabet[y][x] != word[0])
		return false;
	// 원하는 단어가 한 글자인 경우 성공
	if (word.size() == 1)
		return true;
	for (int i = 0; i < 8; ++i) {
		int dy = coordinate[i][0] + y;
		int dx = coordinate[i][1] + x;
		if (hasWord(alphabet, dy, dx, word.substr(1)))
			return true;
	}
	return false;
}

int main() {
	char alphabet[5][5] = {
		{'U','R','L','P','M' },
		{'X','P','R','E','T' },
		{'G','I','A','E','T' },
		{'X','T','N','Z','Y' },
		{'X','O','Q','R','X' } };

	string s;	// 찾을 단어
	int y, x;	// 시작 위치
	cin >> s;
	cin >> y >> x;

	if (hasWord(alphabet, y, x, s))
		cout << "true";
	else
		cout << "false";

	return 0;
}