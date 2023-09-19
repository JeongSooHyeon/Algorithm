#include <iostream>
using namespace std;

int cache[101][101];	

string W;	// ����
int n;	// ���ϸ��� �� 
string S;	// ���ϸ�

// ������ �ε���, ���ϸ��� �ε���
bool match(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1)	return ret;

	//while (w < W.size() && s < S.size() && 
	//		(W[w] == S[s] || W[w] == '?')) {
	//	w++;
	//	s++;
	//}
	if (w < W.size() && s < S.size() &&
		(W[w] == S[s] || W[w] == '?')) {
		return ret = match(w + 1, s + 1);
	}

	// �� while���� �������� Ȯ��
	if (w == W.size()) {	// ���� ������
		return ret = s == S.size();	// ���ڿ��� ������
	}

	// *��� ������ �����ؾ� �ϴ��� �˻�
	if (W[w] == '*') {
		//for(int skip = 0; skip + s <= S.size(); skip++) {
		//	if (match(w + 1, skip + s)) {	
		//		return ret = 1;
		//	}
		//}

		if ((s < S.size() && match(w, s + 1)) 
			|| match(w + 1, s))
			return ret = 1;
	}

	return false;
}

int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;



	for (int i = 0; i < c; i++) {
		cin >> W;	// ����
		cin >> n;	// 1<=n<=50
		for (int j = 0; j < n; j++) {
			memset(cache, -1, sizeof(cache));
			cin >> S;	// 1<=s<=100
			// �Լ� ȣ��
			if (match(0, 0))
				cout <<"�� " << S << endl;
		}
	}

	return 0;
}