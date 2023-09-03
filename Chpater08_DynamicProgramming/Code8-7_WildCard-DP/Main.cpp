/*
���ϵ�ī�� ������ �ذ��ϴ� ���� ��ȹ�� �˰���
*/
#include <iostream>
#include <vector>
using namespace std;

int cache[101][101];	// -1:���� ������ ����, 1:�Էµ��� ���� ������, 0:�Էµ��� ���� �������� ����

// ���ϰ� ���ڿ�
string W, S;

// ���ϵ�ī�� ���� W[w..]�� ���ڿ� S[s..]�� �����Ǵ��� ���θ� ��ȯ
int matchMemoized(int w, int s) {	// �� ���ڿ��� ���� ��ġ
	// �޸������̼�
	int& ret = cache[w][s];
	if (ret != -1)
		return ret;

	// W[w]�� S[s]�� ���糪����.
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}	// ���̻� ������ �� ������ �� while���� �������� Ȯ��

	// ���� ���� �����ؼ� ���� ��� : ���ڿ��� ������� ������
	if (w == W.size())
		return ret = (s == S.size());

	// *�� ������ ���� ��� : *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ��
	if (W[w] == '*') {
		for (int skip = 0; s + skip <= S.size(); ++skip) {
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
		}
	}
}

int main() {
	int c;	// �׽�Ʈ ���̽� �� 1 <= c < 10
	cin >> c;
	string pattern;

	for (int i = 0; i < c; i++) {
		cin >> pattern;
		int n = -1;	// ���� ���� �� 1 <= n <= 50
		cin >> n;

		string fileName;


		for (int j = 0; j < n; j++) {
			cin >> fileName;
			// �Լ� ȣ��
			match(pattern, fileName);
		}

	}

	return 0;
}