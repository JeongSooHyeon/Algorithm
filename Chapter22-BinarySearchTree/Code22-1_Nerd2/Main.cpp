/*
�� ���� �ٸ� ���� ������ϴ��� Ȯ���ϴ� �Լ�
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ���� �ٸ� ���� ��������� �ʴ� ������ ����� ����
// coords[x] = y
map<int, int> coords;
// ���ο� ��(x,y)�� ������ �ٸ� ���鿡 ������ϴ��� Ȯ���Ѵ�.
bool isDominated(int x, int y) {
	// x���� �����ʿ� �ִ� �� �� ���� ���ʿ� �ִ� ���� ã�´�.
	map<int, int>::iterator it = coords.lower_bound(x);	// x �̻��� Ű �� ���� ���� ���� �����ش�.

	// �׷� ���� ������ (x,y)�� ��������� �ʴ´�.
	if (it == coords.end())
		return false;

	// �� ���� x���� �����ʿ� �ִ� �� �� ���� ���� �ִ� ���̹Ƿ�,
	// (x,y)�� ��� ���� ����Ƿ��� �� ������ ����Ǿ�� �Ѵ�.
	return y < it->second;
}


// ���ο� �� (x,y)�� ������ϴ� ������ Ʈ������ �����.
void removeDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);
	// (x,y)���� ���ʿ� �ִ� ���� ����
	if (it == coords.begin())
		return;
	--it;

	// �ݺ��� �Һ��� : it�� (x,y)�� �ٷ� ���ʿ� �ִ� ��
	while (true) {
		// (x,y) �ٷ� ���ʿ� ���� ���� ã�´�.
		// it�� ǥ���ϴ� ���� (x,y)�� ������� �ʴ´ٸ� ���� ����
		if (it->second > y)
			break;
		// ���� ���� �� �����Ƿ� it�� ����� ����
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		// ���� ������ ���ͷ����͸� �ϳ� �Ű� ���� it�� �����
		else {
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}
	}
}

// �� ��(x,y)�� �߰��Ǿ��� �� coords�� �����ϰ�,
// �ٸ� ���� ��������� �ʴ� ������ ������ ��ȯ
int registered(int x, int y) {
	// (x,y)�� �̹� ������ϴ� ��쿡�� �׳� (x,y)�� ������.
	if (isDominated(x, y))
		return coords.size();
	// ������ �ִ� �� �� (x,y)�� ������ϴ� ������ �����.
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}

int main() {
	int c;	
	cin >> c;

	int n;	// ���� ��û�� ������� ��	10<=n<=50000
	int p, q;	// ���� ��, ��� �׸� ��, 0<=p,q<=100000
	vector<vector<int>> v;
	for(int i = 0; i < c; i++) {
		int result = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> p >> q;
			coords[p] = q;
			result += registered(p, q);
		}
		cout <<"result : " << result << endl;
		map<int, int>().swap(coords);
	}

	return 0;
}