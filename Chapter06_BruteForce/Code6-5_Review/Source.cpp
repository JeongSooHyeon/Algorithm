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
		if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size())	// ¹üÀ§ °Ë»ç
			ok = false;
		else if ((board[y][x] += isCover) > 1)	// ÀÌ¹Ì µ¤Àº °Å
			ok = false;
	}
	return ok;
}

int cover(vector<vector<int>>& board) {
	// Èò »ö Ã£±â
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
	// ±âÀú »ç·Ê : ´Ù µ¤À¸¸é ³¡
	if (row == -1 && col == -1)
		return 1;

	int ret = 0; 
	for (int i = 0; i < 4; ++i) {
		if (set(board, i, row, col, 1))	// µ¤¾î
			ret += cover(board);
		set(board, i, row, col, -1);	// °È¾î
	}
	return ret;
}

int main() {
	int c;	// Å×½ºÆ® ÄÉÀÌ½ºÀÇ ¼ö (c <= 30)
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
				if (width[k] == '.')	// Èò Ä­
					temp.push_back(0);
				else					// °ËÀº Ä­
					temp.push_back(1);
			}
			board.push_back(temp);
		}
		cout << cover(board) << endl;
	}
}