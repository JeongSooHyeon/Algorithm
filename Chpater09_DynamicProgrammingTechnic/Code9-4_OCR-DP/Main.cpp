/*
���� ���� �ν� ������ �ذ��ϴ� ���� ��ȹ�� �˰���
*/
#include <iostream>
using namespace std;

int n, m;
// �з��Ⱑ ��ȯ�� ����. �ܾ� ��ȣ�� ��ȯ�Ǿ� ����
int R[100];
// T[i][j] = i �ܾ� ���Ŀ� j �ܾ ���� Ȯ���� �αװ�
double T[501][501];
// M[i][j] = i �ܾ j �ܾ�� �з��� Ȯ���� �α� ��
double M[501][502];
int choice[102][502];
double cache[102][502];	// 1�� �ʱ�ȭ


// Q[segment] ���ĸ� ä���� ���� �� �ִ� �ִ� g() ���� �αװ��� ��ȯ
// Q[segment-1] == previousMatch��� ����
double recognize(int segment, int previousMatch) {
	if (segment == n)	return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0)	return ret;

	ret = -1e200;	// log(0) = ���� ���Ѵ뿡 �ش��ϴ� ��
	int& choose = choice[segment][previousMatch];

	// R[segment]�� �����Ǵ� �ܾ ã�´�.
	for (int thisMatch = 0; thisMatch < m; thisMatch++) {
		// g(thisMatch) = T(previousMatch, thisMatch) * M(thisMatch, R[segment]
		double cand = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment + 1, thisMatch);

		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}

// �Է¹��� �ܾ���� ���
string corpus[501];
string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
	string ret = corpus[choose];
	if (segment < n - 1)
		ret = ret + " " + reconstruct(segment + 1, choose);
	return ret;
}

int main() {
	int m;	// ������ ������ �� �ִ� �ܾ��� �� 1<=m<=500
	int q;	// ó���ؾ� �� ������ �� 1<=q<=100
	cin >> m >> q;
	string words[500];
	double B[500];
	for (int i = 0; i < m; i++) {
		cin >> words[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];	// i�� �ܾ ù �ܾ�� ������ Ȯ��
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> T[i][j];	// i�� �ܾ��� ���� �ܾ j�� �ܾ��� Ȯ��
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];	// i�� �ܾ ���� ������ j�� �ܾ�� �з��� Ȯ��
		}
	}

	int n;	// �ܾ��� �� 1<=n<=100
	
	for (int i = 0; i < q; i++) {
		cin >> n;

	}
}