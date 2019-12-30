#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

int n = 0, m = 0, v = 0;
int c1[1001];
int c2[1001];
vector<int> a[1001];
queue<int> q;

void dfs(int x) {
	if (c1[x])
		return;

	c1[x] = true;
	cout << x << ' ';

	// 내림차순 정렬 
	for (int i = 0; i < a[x].size(); i++) {
		for(int j = 1; j < a[x].size(); j++) {
			if(a[x][j - 1] > a[x][j]) {
				int temp = a[x][j];
				a[x][j] = a[x][j-1];
				a[x][j-1] = temp;
			}
		}
	}
		
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}


void bfs(int start) {
	q.push(start);
	c2[start] = true;
	int temp = 0;
	
	// 내림차순 정렬 
	for (int i = 0; i < a[start].size(); i++) {
		for(int j = 1; j < a[start].size(); j++) {
			if(a[start][j - 1] > a[start][j]) {
				int temp = a[start][j];
				a[start][j] = a[start][j-1];
				a[start][j-1] = temp;
			}
		}
	}
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		c2[x] = true;

		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];

			if (!c2[y]) {
				q.push(y);
				c2[y] = true;
			}
		}
	}
}


int main() {
	cin >> n >> m >> v;
	int n1, n2;

	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		a[n1].push_back(n2);
		a[n2].push_back(n1);
	}
	
	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;
}
