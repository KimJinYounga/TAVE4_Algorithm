#include<iostream>
#include<queue>
using namespace std;

queue<int> que;
queue<int> que2;

int main() {
	int N, M;
	int first = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		que.push(i);
	while (que.empty() != true) {
		for (int j = 0; j < M-1; j++) {
			first = que.front();
			que.pop();
			que.push(first);
		}
		que2.push(que.front());
		que.pop();
	}
	int size = que2.size();
	cout << "<";
	for (int i = 0; i < size; i++) {
		cout<<que2.front();
		if (i != size - 1) cout << ", ";
		que2.pop();
	}
	cout << ">";
}
