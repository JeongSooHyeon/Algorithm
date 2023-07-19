#include <iostream>
using namespace std;

#define MAX_SIZE 2000

char decompressed[MAX_SIZE][MAX_SIZE];
// s를 압축 해제해서 decompressed[y..y + size - 1][x..x + size -1 ] 구간에 쓴다
void decompress(string::iterator& it, int y, int x, int size) {
	// 한 글자를 검사할 때마다 반복자를 한 칸 앞으로 옮긴다.
	char head = *(it++);

	// 기저 사례 : 첫 글자가 b 또는 w인 경우
	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; ++dy) {
			for (int dx = 0; dx < size; ++dx) {
				decompressed[y + dy][x + dx] = head;
			}
		}
	}
	else {
		// 네 부분을 각각 순서대로 압축 해제한다.
		int half = size / 2;
		decompress(it, y, x, half);
		decompress(it, y, x + half, half);
		decompress(it, y + half, x, half);
		decompress(it, y + half, x + half, half);
	}
}

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	
	// 기저사례
	if (head == 'b' || head == 'w')
		return string(1, head);

	// 다음 조각 뒤집기
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	// 각각 위와 아래 조각들의 위치를 바꾼다.
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	int c;	// 테스트 케이스 (c<=50)
	// 문자열 길이 1000이하, 원본 그림의 크기 2^20 * 2^20


	for (int i = 0; i < 4; ++i) {
		string quadStr;
		cin >> quadStr;
		string::iterator it = quadStr.begin();
		cout << reverse(it) << endl;
	}
	return 0;
}