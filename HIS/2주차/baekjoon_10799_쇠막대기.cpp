#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	string temp;
	cin >> temp;
	stack<char> s;
	stack<char> r;

	int cnt = 0;
	for (int i = 0; i < temp.length(); i++)
		s.push(temp[i]);

	while (!s.empty()) {
		char t = s.top();
		s.pop();
		// )가 나오는 경우 그 다음이 (인지 체크 필요
		if (t == ')') {
			// (), 즉, 레이저인 경우
			if (s.top() == '(') {
				cnt += r.size(); // 남아있는 r 갯수만큼 추가
				s.pop();
			}
			// ), 즉, 철판의 시작 경우
			else
				r.push(')');
		}
		// (, 즉, 철판의 끝인 경우
		else if (t == '(') {
			cnt += 1; // 철판 하나 종료시키면서 cnt + 1
			r.pop();
		}
	}
	cout << cnt << endl;
}