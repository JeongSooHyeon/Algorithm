#include <iostream>
#include <vector>
using namespace std;

int blockL[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool set(vector<vector<int>>& board, int type, int r, int c, int isCover) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		int y = blockL[type][i][0] + r;
		int x = blockL[type][i][1] + c;
		if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size())	// ���� �˻�
			ok = false;
		else if ((board[y][x] += isCover) > 1)	// �̹� ���� ��
			ok = false;
	}
	return ok;
}

int cover(vector<vector<int>>& board) {
	// �� �� ã��
	int row=-1, col=-1;
	bool flag = false;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j] == 0) {
				row = i, col = j;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	// ���� ��� : �� ������ ��
	if (row == -1 && col == -1)
		return 1;

	int ret = 0; 
	for (int i = 0; i < 4; ++i) {
		if (set(board, i, row, col, 1))	// ����
			ret += cover(board);
		set(board, i, row, col, -1);	// �Ⱦ�
	}
	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽��� �� (c <= 30)
	cin >> c;
	string width;
	int h, w;
	for (int i = 0; i < c; ++i) {
		vector<vector<int>> board;
		cin >> h >> w;
		for (int j = 0; j < h; ++j) {
			vector<int> temp;
			cin >> width;
			for (int k = 0; k < w; ++k) {
				if (width[k] == '.')	// �� ĭ
					temp.push_back(0);
				else					// ���� ĭ
					temp.push_back(1);
			}
			board.push_back(temp);
		}
		cout << cover(board) << endl;
	}
}