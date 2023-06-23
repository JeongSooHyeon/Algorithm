/*
6.6 ∞‘¿”∆« µ§±‚
*/

#include <iostream>
#include <string>
using namespace std;


int whiteCnt = 0;
int countCovering(string s[20], int blockL[4][3],int h, int w) {

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == '.')
				whiteCnt++;
		}
	}
	if (whiteCnt <= 0)	// »Ú ƒ≠ ¥Ÿ √§øÚ
		return 1;
	if (whiteCnt % 3 != 0)	// 3¿« πËºˆ∞° æ∆¥‘
		return 0;

	int idxi = -1, idxj=-1;
	for (int i = 0; i < h; ++i) {	// √ππ¯¬∞ «œæ· ƒ≠
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == '.') {
				idxi = i;
				idxj = j;
				break;
			}
		}
	}

	if (idxi == -1 || idxj == -1)	// ¥Ÿ √§øÚ
		return 1;
	int ret = 0;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if(blockL[i][j]*idxj)
		}
	}
	
}

int main() {
	int c;	// ≈◊Ω∫∆Æ ƒ…¿ÃΩ∫ ºˆ, c <= 30
	int h=-1, w=-1;	// 1 <= h,w <= 20
	string s[20];	// # ∞À¿∫ƒ≠, . »Úƒ≠

	cin >> c;
	string str;
	for (int i = 0; i < c; ++i) {
		cin >> h >> w;
		int blockL[4][3] = {{ 1, 1 + w, 2 + w },
							{1, 2 + w, 3 + w},
							{1,2,1 + w},
							{1,2,2 + w}};
		for (int j = 0; j < h; ++j) {
			cin >> str;
			s[i] = str;
		}
		cout << countCovering(s, blockL, h, w) << endl;
	}



	return 0;
}