#include<iostream>
#include<queue>
using namespace std;
int N;
char map[26][3];
queue<char> q;

void pre(char input) {
	q.push(input);
	for (int i = 0; i < N; i++) {
		if (map[i][0] == input) {
			if (map[i][1] != '.')
				pre(map[i][1]);
			if (map[i][2] != '.')
				pre(map[i][2]);
		}
	}
}

void in(char input) {
	for (int i = 0; i < N; i++) {
		if (map[i][0] == input) {
			if (map[i][1] != '.')
				in(map[i][1]);
			q.push(input);
			if (map[i][2] != '.')
				in(map[i][2]);
		}
	}
}

void post(char input) {
	for (int i = 0; i < N; i++) {
		if (map[i][0] == input) {
			if (map[i][1] != '.')
				post(map[i][1]);
			if (map[i][2] != '.')
				post(map[i][2]);
			q.push(input);
		}
	}
}

void printQ() {
	int size = q.size();
	for (int i = 0; i < size; i++) {
		cout << q.front();
		q.pop();
	}
	cout << endl;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> map[i][0] >> map[i][1] >> map[i][2];
	pre('A');
	printQ();
	in('A');
	printQ();
	post('A');
	printQ();
}