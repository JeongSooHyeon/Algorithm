#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool wellMatched(const string& formula) {
	// ���� ��ȣ ���ڵ�� �ݴ� ��ȣ ���ڵ�
	const string opening("({["), closing(")}]");

	// �̹� ���� ��ȣ���� ������� ��� ����
	stack<char> openStack;

	for (int i = 0; i < formula.size(); i++) {
		// ���� ��ȣ���� �ݴ� ��ȣ���� Ȯ���Ѵ�
		if (opening.find(formula[i]) != -1)	// ���� ��ȣ��� ������ ���ÿ� ���� �ִ´�
			openStack.push(formula[i]);

		else {	// �� ���� ��� ���� �� ���� ���ڿ� ���纸��
			// ������ ��� �ִ� ��� ����
			if (openStack.empty())
				return false;

			// ���� ¦�� ���� �ʾƵ� ����
			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;

			// ¦�� ���� ��ȣ�� ���ÿ��� ����
			openStack.pop();
		}
		// ������ ���� ��ȣ�� ����� ����
		return openStack.empty();
	}
}





string s;	// 1<=length<=10000

bool solve() {
	int len = s.length();
	stack<char> st;

	int i = 0;
	char temp;
	while (i < len) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);	// ���� ��ȣ �ֱ�
		}
		else {

			temp = st.top();
			st.pop();
			switch (s[i])
			{
			case ')':
				if (temp != '(')
					return false;
				break;
			case '}':
				if (temp != '{')
					return false;
				break;
			case ']':
				if (temp != '[')
					return false;
				break;
			}
		}
		i++;
	}
	return true;
}

int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> s;
		cout << (solve() ? "YES" : "NO") << endl;
	}

	return 0;
}