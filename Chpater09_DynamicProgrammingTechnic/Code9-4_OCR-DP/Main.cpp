/*
���� ���� �ν� ������ �ذ��ϴ� ���� ��ȹ�� �˰���
*/
#include <iostream>
#include <cmath>
using namespace std;

int n, m;	// �˻��� ������ �ܾ��� �� 1<=n<=100, ������ ������ �� �ִ� �ܾ��� ��
// �Է¹��� �ܾ���� ���
string corpus[501];
// �з��Ⱑ ��ȯ�� ����. �ܾ� ��ȣ�� ��ȯ�Ǿ� ����
int R[100];
// T[i][j] = i �ܾ� ���Ŀ� j �ܾ ���� Ȯ���� �αװ�
double T[501][501];
// M[i][j] = i �ܾ j �ܾ�� �з��� Ȯ���� �α� ��
double M[501][502];
int choice[102][502];
double cache[102][502];	// 1�� �ʱ�ȭ
double B[501];	// �ش� �ܾ ù�ܾ�� �� Ȯ��

// Q[segment] ���ĸ� ä���� ���� �� �ִ� �ִ� g() ���� �αװ��� ��ȯ
// Q[segment-1] == previousMatch��� ����
double recognize(int segment, int previousMatch) {
	// ���� ��� : ���� ������ �˻�
	if (segment == n)	return 0;

	// �޸������̼�
	double& ret = cache[segment+1][previousMatch+1];
	if (ret != 1.0)	return ret;

	ret = -1e200;	// log(0) = ���� ���Ѵ뿡 �ش��ϴ� ��
	int& choose = choice[segment+1][previousMatch+1];

	// R[segment]�� �����Ǵ� �ܾ ã�´�.
	for (int thisMatch = 0; thisMatch < m; thisMatch++) {
		// g(thisMatch) = T(previousMatch, thisMatch) * M(thisMatch, R[segment])
		// ���� �ܾ��� �������� �� �ܾ��� Ȯ�� * ���� �ܾ ��ȯ�� �ܾ�� �з��� Ȯ��
		double cand = 0.0;
		// Ȯ���� �αװ��� ��
		if (previousMatch == -1) {
			cand = log(B[R[0]]) + log(M[thisMatch][R[segment]])
				+ recognize(segment + 1, thisMatch);
		}
		else
			cand = log(T[previousMatch][thisMatch]) + log(M[thisMatch][R[segment]]) 
			+ recognize(segment + 1, thisMatch);

		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}

string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment+1][previousMatch+1];
	string ret = corpus[choose];
	if (segment < n-1)
		ret = ret + " " + reconstruct(segment+1, choose);
	return ret;
}

int main() {
	//int m;	// ������ ������ �� �ִ� �ܾ��� �� 1<=m<=500
	int q;	// ó���ؾ� �� ������ �� 1<=q<=100
	cin >> m >> q;
	
	for (int i = 0; i < m; i++) {
		cin >> corpus[i];
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

	string temp;
	for (int i = 0; i < q; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> temp;
			for (int k = 0; k < m; k++) {
				if (temp == corpus[k]) {
					R[j] = k;
					break;
				}
			}
		}

		fill(&cache[0][0], &cache[0][0]+102*502, (double)1.0);
		//recognize(1, 0);
		cout << "Ȯ�� : " << recognize(0, -1) << endl;
		
		cout << reconstruct(0, -1) << " ";

		cout << endl;
	}
}