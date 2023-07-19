#include <iostream>
using namespace std;

#define MAX_SIZE 2000

char decompressed[MAX_SIZE][MAX_SIZE];
// s�� ���� �����ؼ� decompressed[y..y + size - 1][x..x + size -1 ] ������ ����
void decompress(string::iterator& it, int y, int x, int size) {
	// �� ���ڸ� �˻��� ������ �ݺ��ڸ� �� ĭ ������ �ű��.
	char head = *(it++);

	// ���� ��� : ù ���ڰ� b �Ǵ� w�� ���
	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; ++dy) {
			for (int dx = 0; dx < size; ++dx) {
				decompressed[y + dy][x + dx] = head;
			}
		}
	}
	else {
		// �� �κ��� ���� ������� ���� �����Ѵ�.
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
	
	// �������
	if (head == 'b' || head == 'w')
		return string(1, head);

	// ���� ���� ������
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	// ���� ���� �Ʒ� �������� ��ġ�� �ٲ۴�.
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	int c;	// �׽�Ʈ ���̽� (c<=50)
	// ���ڿ� ���� 1000����, ���� �׸��� ũ�� 2^20 * 2^20


	for (int i = 0; i < 4; ++i) {
		string quadStr;
		cin >> quadStr;
		string::iterator it = quadStr.begin();
		cout << reverse(it) << endl;
	}
	return 0;
}