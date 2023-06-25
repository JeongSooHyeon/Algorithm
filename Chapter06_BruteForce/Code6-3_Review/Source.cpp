#include <iostream>
#include <vector>
using namespace std;

int coordinate[8][2] = {
	{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}
};

bool hasWord(char alphabet[5][5], int y, int x, string word) {
	// ���� ��� : ���� ��ġ�� ���� ���̸� ����
	if (y >= 5 || y < 0 || x >= 5 || x < 0)
		return false;
	// ���� ��� : ù ���ڰ� �ƴ� ��� ����
	if (alphabet[y][x] != word[0])
		return false;
	// ���ϴ� �ܾ �� ������ ��� ����
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

	string s;	// ã�� �ܾ�
	int y, x;	// ���� ��ġ
	cin >> s;
	cin >> y >> x;

	if (hasWord(alphabet, y, x, s))
		cout << "true";
	else
		cout << "false";

	return 0;
}