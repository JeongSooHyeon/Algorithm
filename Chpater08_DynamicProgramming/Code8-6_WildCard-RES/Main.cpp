/*
���ϵ�ī�� ������ �ذ��ϴ� ���� Ž�� �˰���
*/
#include <iostream>
#include <vector>
using namespace std;



int match(const string& w, const string& s) {
	// w[pos]�� s[pos]�� ���糪����.
	int pos = 0;
	while (pos < s.size() && pos < w.size() &&
		(w[pos] == '?' || w[pos] == s[pos])) {	// *�� �����ų�, �� �� �� ���ڿ��� ���� �� ����
		++pos;
	}	// ���̻� ������ �� ������ �� while���� �������� Ȯ��

	// ���� ���� �����ؼ� ���� ��� : ���ڿ��� ������� ������
	if (pos == w.size())
		return pos == s.size();

	// *�� ������ ���� ��� : *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ��
	if (w[pos] == '*') {
		for (int skip = 0; pos + skip <= s.size(); ++skip) {
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	}

	// �� ���� ��쿡�� ��� �������� �ʴ´�
	return false;

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