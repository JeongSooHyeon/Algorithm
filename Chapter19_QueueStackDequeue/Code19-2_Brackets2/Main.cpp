#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool wellMatched(const string& formula) {
	// 여는 괄호 문자들과 닫는 괄호 문자들
	const string opening("({["), closing(")}]");

	// 이미 열린 괄호들을 순서대로 담는 스택
	stack<char> openStack;

	for (int i = 0; i < formula.size(); i++) {
		// 여는 괄호인지 닫는 괄호인지 확인한다
		if (opening.find(formula[i]) != -1)	// 여는 괄호라면 무조건 스택에 집어 넣는다
			openStack.push(formula[i]);

		else {	// 이 외의 경우 스택 맨 위의 문자와 맞춰보기
			// 스택이 비어 있는 경우 실패
			if (openStack.empty())
				return false;

			// 서로 짝이 맞지 않아도 실패
			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;

			// 짝을 맞춘 괄호는 스택에서 뺀다
			openStack.pop();
		}
		// 닫히지 않은 괄호가 없어야 성공
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
			st.push(s[i]);	// 여는 괄호 넣기
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
	int c;	// 테스트 케이스
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> s;
		cout << (solve() ? "YES" : "NO") << endl;
	}

	return 0;
}