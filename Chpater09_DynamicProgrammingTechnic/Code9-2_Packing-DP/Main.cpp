/*

*/
#include <iostream>
#include <vector>
using namespace std;

int n;	// �������� ���� ������ �� 1<=n<=100
int w;	// ĳ���� �뷮 1<=w<=1000
string name[100];	// ���� �̸� 
int volume[100], need[100];	// ���� ����, ���ڵ� <=1000

int cache[1001][101];
int choices[101];
// ĳ��� ���� �뷮�� capacity�� ��, item ������ ���ǵ���
// ��� ���� �� �ִ� �ִ� ���ڵ��� �� ��ȯ
int pack(int capacity, int item) {	
	// ���� ��� : �� ���� ������ ���� ��
	if (item == n)	return 0;

	// �޸������̼�
	int ret = cache[capacity][item];
	if (ret != -1)	return ret;

	// �� ������ ���� ���� ���
	ret = pack(capacity, item + 1);

	// �� ������ ���� ���
	if (capacity >= volume[item]) {
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	}
	
	return ret;
}

// pack(capacity, item)�� ������ ���ǵ��� ����� picked�� ����
void reconstruct(int capacity, int item, vector<string>& picked) {
	// ���� ��� : ��� ������ �� �������
	if (item == n)	return;

	if (pack(capacity, item) == pack(capacity, item + 1)) {	// item�� ���õ��� ���� ��
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;

	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> w;
		for (int j = 0; j < n; j++) {
			cin >> name[j] >> volume[j] >> need[j];	// �̸�, ����, ���ڵ�
		}
		// �Լ� ȣ��
		cout << pack(w, 0) << ' ';
		vector<string> picked;
		reconstruct(w, 0, picked);
		cout << picked.size() << endl;
		for (int i = 0; i < picked.size(); i++)
			cout << picked[i] << endl;
	}

	return 0;
}