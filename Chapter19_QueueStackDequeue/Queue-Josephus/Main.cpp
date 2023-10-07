#include <iostream>
#include <queue>
using namespace std;

int n, k;	// 3<=n, k<=1000	// k��° ����� �ڻ�

// ������ ��Ƴ��� �� ����� ��ȣ ��������
void Josephus(int n, int k) {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	while (q.size() > 2) {
		q.pop();	// ù��° ��� �̱�
		for (int i = 0; i < k - 1; i++) {	// k-1�� �ű��
			int temp = q.front();	// �� �ջ��
			q.pop();	// �̾Ƽ�
			q.push(temp);	// �ڿ� ���̱�
		}
	}
}



int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> k;

		Josephus(n, k);
	}

	return 0;
}