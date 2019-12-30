
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int laser(string);
int main()
{
	string str;
	cin >> str;
	cout << laser(str) << endl;

	return 0;
}
int laser(string str){
		stack<char> cstack;
		int result = 0;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') cstack.push(str[i]);
			else {
				cstack.pop();
				if (str[i - 1] == '(') result += cstack.size();
				else result++;
			}
		}
		return result;
	}