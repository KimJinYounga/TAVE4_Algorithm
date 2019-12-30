#include<iostream>
#include<queue>
using namespace std;
int N, M, V;
bool visited[1001][1001];
/*
입력 순서가 정렬되있지 않기 때문에,
vector, queue 등을 사용하면 정렬 절차가 추가로 필요
그에 비해, 2차 행렬은 특성상 자동 정렬되므로 편함
*/
int map[1001][1001];
/*
지금의 내 역량으로는 bfs는 거의 무조건 queue를 써야함
거의 공식적임
*/
queue<int>q;

void setZero() {
	for (int y = 0; y <= N; y++)
		for (int x = 0; x <= N; x++)
			map[y][x] = 0;
}

void refresh() {
	for (int y = 0; y <= N; y++)
		for (int x = 0; x <= N; x++)
			visited[y][x] = false;
	cout << "\n" << V << " ";
}

/*
dfs에서는 자료구조를 사용하지 않음.
단, for문에 의한 논리 구조를 사용함

y축이 start인 열의 원소 중 값이 1인 녀석들에게 재귀적으로 방문.
논리적으로 dfs와 같은 형식이 된다.

visited[a][b]는 a와 b의 연결을 탐색했는지 여부를 기록
visited[a][a]는 a라는 노드가 이미 탐색이 완료되었는지 여부를 기록
*/

void dfs(int start) {
	cout << start << " ";
	visited[start][start] = true;
	for (int i = 1; i <= N; i++) {
		if (map[start][i] == 1 && !visited[start][i] && !visited[i][i]) {
			visited[start][i] = true;
			visited[i][start] = true;
			visited[i][i] = true;
			dfs(i);
		}
	}
}

/*
dfs와 마찬가지로 y축이 start인 열의 원소 중 값이 1인 녀석들을
재귀적으로 방문하는 것이 아니라, 출력만 시키고 queue에 넣어두었다가
그것들에 대해 선입선출 순서로 그것들의 자식에 방문함.
*/

void bfs(int start) {
	visited[start][start] = true;
	for (int i = 1; i <= N; i++) {
		if (map[start][i] == 1 && !visited[start][i] && !visited[i][i]) {
			visited[start][i] = true;
			visited[i][start] = true;
			visited[i][i] = true;
			cout << i << " ";
			q.push(i);
		}
	}
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		bfs(n);
	}
}

int main() {
	int t1, t2;
	cin >> N >> M >> V;
	setZero();
	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2;
		map[t1][t2] = 1;
		map[t2][t1] = 1;
	}
	dfs(V);
	refresh();
	bfs(V);
}