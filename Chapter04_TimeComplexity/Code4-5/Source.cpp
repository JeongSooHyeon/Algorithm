/*
4.5 ���� �޴� ���ϱ�
*/

#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

// �� �޴��� ��ΰ� �Ļ��� �� �ִ��� ���θ� ��ȯ�Ѵ�.
bool canEverybodyEat(const vector<int>& menu);

int m;	// �丮�� �� �ִ� ������ ���� ��

// food ��° ������ ������ ���θ� �����Ѵ�.
int selectMenu(vector<int>& menu, int food) {
	// ���� ��� : ��� ���Ŀ� ���� ������ ���θ� �������� ��
	if (food == m) {
		if (canEverybodyEat(menu))	
			return menu.size();
		// �ƹ��͵� �� �Դ� ����� ������ ���� ū ���� ��ȯ
		return INF;
	}
	// �� ������ ������ �ʴ� ����� ���� ���
	int ret = selectMenu(menu, food + 1);
	// �� ������ ����� ����� ���� ����ؼ� �� ���� ���� ���Ѵ�.
	menu.push_back(food);
	ret = min(ret, selectMenu(menu, food + 1));
	menu.pop_back();
	return ret;
}