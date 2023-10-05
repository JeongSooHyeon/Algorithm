#include <iostream>
#include <list>
using namespace std;

int n, k;	// 3<=n, k<=1000	// k��° ����� �ڻ�

// ������ ��Ƴ��� �� ����� ��ȣ ��������
void Josephus(int n, int k) {
	// ����Ʈ �غ�
	list<int> survivors;
	for (int j = 0; j < n; j++) {
		survivors.push_back(j + 1);
	}

	// �̹��� ���� ���
	list<int>::iterator kill = survivors.begin();
	while (n > 2) {
		// ù ��° ����� �ڻ�, erase()�� ���� ������ ���� ���� ��ȯ
		kill = survivors.erase(kill);
		if (kill == survivors.end()) {	// ���� ����
			kill = survivors.begin();	// ó������ ���ư�
		}
		--n;

		// k-1�� ���� ������� �ű��.
		for (int i = 0; i < (k - 1) % n; i++) {
			if (++kill == survivors.end())
				kill = survivors.begin();
		}
	}
	cout << survivors.front() << ' ' << survivors.back() << endl;
}



int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> k;

		Josephus(n ,k);
	}

	return 0;
}