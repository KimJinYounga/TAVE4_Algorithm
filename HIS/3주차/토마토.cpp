#include<iostream>
#include<queue>
using namespace std;
int M, N;
int map[1000][1000]; // 입력받은 초기 토마토 상태 셋팅을 저장하는 2차배열
int visited[1000][1000]; // 각 원소에 몇 초 후에 도착했는지 기록하는 2차배열
						 // 자동적으로, 방문 여부도 기록할 수 있게 된다.
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pair<int, int>>q;

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= 0 && ny < M && nx >= 0 && nx < N){
				if (visited[ny][nx] == 0 && map[ny][nx] == 0) {
					visited[ny][nx] = visited[y][x] + 1;
					map[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int y = 0; y < M; y++)
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			visited[y][x] = 0;
			if (map[y][x] == 1)
				q.push(make_pair(y, x));
		}
	bfs();
	int max = 0;
	// 마지막으로 map을 모두 돌 때, 0이 남아있으면 -1 출력
	// 0이 없으면, 최대 visited원소를 출력
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 0) {
				cout << "-1" << endl;
				return 0;
			}
			if (visited[y][x] > max)
				max = visited[y][x];
		}
	}
	cout << max << endl;
	return 0;
}