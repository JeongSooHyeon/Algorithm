/*
���ϵ� ī��
*/
#include <iostream>
#include <vector>
using namespace std;


int cache[100][100];

string w;	// ���ϵ�ī�� ����
int n;	// ���ϸ��� �� 1<=n<=50
vector<string> v(50);

// ? : �ƹ� ����, * : 0���� �̻��� �ƹ� ���ڿ�
void wildCard() {
	// ���� ��� : 

	// �޸������̼�

	// ���
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
			wildCard();
		}
	}

}

