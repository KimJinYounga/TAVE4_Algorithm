#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

/*
error : visual studio17에서는 scanf가 안정성문제(?)로 scanf_s로 작성해야 에러가 안나는데 비해, 백준 boj는 scanf로 작성해야 에러가 안난다.
특징 : 입력값을 쓸데없이 100자리 긴 int형으로 받기 때문에, cstdio를 include해서, %1d를 통해 한 자리씩 입력받아야한다. 코테에서 적용하기 좋은 코드!
*/

int N, M;
int map[101][101];
int visited[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

// 입력값을 100자리로 받기 때문에, long long으로도 힘들다. cstdio를 include해서 %1d를 통해 한 자리씩 입력받아야한다.
void inputData() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			int b;
			scanf_s("%1d", &b); // 한 자리 씩 입력받기 위한 코드
			map[y][x] = b; // 입력받은 값을 지정된 map 좌표에 저장
		}
	}
}

void bfs(int y, int x) {
	if (y == N && x == M)
		return;
	// 4방면 탐색
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 1 && ny <= N && nx >= 1 && nx <= M) {
			if (visited[ny][nx] == 0 && map[ny][nx] == 1) {
				/*
				y, x까지 가는데 드는 비용을 bfs를 통해 visited[ny][nx] = visited[y][x] + 1 로 기록하고
				ny, nx를 queue에 넣어서 bfs 동작
				*/
				visited[ny][nx] = visited[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	// queue에 있는 좌표 싹 다 탐색 돌리기!
	while (!q.empty()) {
		int _y = q.front().first;
		int _x = q.front().second;
		q.pop();
		bfs(_y, _x);
	}
}

int main() {
	cin >> N >> M;
	// 여기서 visited는 bool이 아닌 int이기 때문에, 0으로 초기화가 필요하다.
	for (int y = 1; y <= N; y ++ )
		for (int x = 1; x <= M; x++)
			visited[y][x] = 0;
	inputData();
	bfs(1, 1);
	// 결론적으로 visited[N][M]에 최소 방문 비용이 저장된다.
	cout << visited[N][M] + 1 << endl;
}


