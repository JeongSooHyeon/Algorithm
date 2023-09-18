/*
���ϵ� ī��
*/
#include <iostream>
#include <vector>
using namespace std;


int cache[101][101];
string W, S;

bool matchMemoized(int w, int s) {
	// �޸������̼�
	int& ret = cache[w][s];
	if (ret != -1) return ret;

	// W[s]�� S[s]�� ���� ������.
	while (s < S.size() && w < W.size() &&
		(W[w] == '?' || W[w] == S[s])) {
		++s;
		++w;
	}
	// �ݺ��� ���ֱ�
	if (w < W.size() && s < S.size() &&
		(W[w] == '?' || W[w] == S[s]))
		return ret = matchMemoized(w + 1, s + 1);




	if (w == W.size())
		return ret = (s == S.size());




	if (W[w] == '*') {
		for (int skip = 0; skip + s <= S.size(); skip++) {
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
		}
	}
	// �ݺ��� ���ֱ�
	if (W[w] == '*') {
		if (matchMemoized(w + 1, s) ||	// ���� ��Ű�� ���� ������
			(s < S.size() && matchMemoized(w, s + 1)))	// �� ���ڸ� �� ������ų ������ ����
			return ret = 1;
	}

	return ret = 0;
}

string w;	// ���ϵ�ī�� ����
int n;	// ���ϸ��� �� 1<=n<=50
vector<string> v(50);

// ? : �ƹ� ����, * : 0���� �̻��� �ƹ� ���ڿ�
bool match(const string& w, const string& s) {
	// w[pos]�� s[pos]�� ���糪����
	int pos = 0;
	while (pos < s.size() && pos < w.size() &&
		(w[pos] == '?' || w[pos] == s[pos]))
		++pos;

	// ���̻� ������ �� ������ �� while���� �������� Ȯ��
	// 1. w[pos]�� s[pos]�� �������� ���� - ���� ����
	// 2. w ���� ���� - *�� �ϳ��� ���� ���, ���ϰ� ���ڿ��� ���̰� ���ƾ� ����
	if (pos == w.size())
		return pos == s.size();

	// 3. s ���� ���� - ���� ������ *�� ����(4������ ó��)
	// 4. s[pos]�� * - �� ���� �����Ǵ��� 0���� ���� ���ڿ��� ���̱��� ��ȸ
	// w�� pos+1 ���� ����, s�� pos+skip ���� ���ڿ� match()
	if (w[pos] == '*') {
		for (int skip = 0; pos + skip < s.size(); skip++) {
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	}

	// �� ���� ��� ��� �������� ����
	return false;

}



int main() {
	int c;
	cin >> c;


	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> w;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			// match();
		}
	}

}

