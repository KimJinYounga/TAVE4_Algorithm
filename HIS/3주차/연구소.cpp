#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>>v;
int map[8][8];
int tempMap[8][8];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int N, M, ans = 0;

void bfs() {
	// map에서 바이러스가 퍼지는 것을 기록하기 위해, 초기 map과 같은 모양의 tempMap을 복사해둔다.
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			tempMap[y][x] = map[y][x];
			if (map[y][x] == 2)
				v.push_back(make_pair(y, x));
		}
	// v의 원소는 바이러스 좌표. 바이러스 좌표를 모두 확인할 때 까지 돌면서, 바이러스 근처의 0 위치는 2로 감염시키고, 0 좌표를 v에 push
	while (!v.empty()) {
		int y = v.back().first;
		int x = v.back().second;
		v.pop_back();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (tempMap[ny][nx] == 0) {
					tempMap[ny][nx] = 2;
					v.push_back(make_pair(ny, nx));
				}
			}
		}
	}
	// 바이러스에 잠식된 tempMap에서 0에 해당하는 안전구역 갯수 세기
	int cnt = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (tempMap[y][x] == 0)
				cnt++;
	if (cnt > ans)
		ans = cnt;
}

void makeWall(int cnt) {
	// cnt = 3이 되는 경우 종료!
	if (cnt == 3) {
		bfs();
		return;
	}
	// ex) cnt = 0 ,  즉, 벽 하나도 안 세운 경우 모든 map 원소를 탐색하다가
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			// 벽이 없는 0 위치 찾으면
			if (map[y][x] == 0) {
				map[y][x] = 1; // 임시로 벽을 세운 다음에
				makeWall(cnt + 1); // 벽 1개 세운 경우에 해당하는 재귀를 돌리고
				map[y][x] = 0; // 위의 재귀가 끝나고 빠져나오면 현재 임시로 세워본 벽을 0으로 바꿔서 허무는 작업
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	makeWall(0);

	cout << ans << endl;
}

/*
1. 벽을 세우고
2. 벽 3개 세운 경우, 안전 구역 탐색을 위한 dfs 적용하고
3. dfs결과 안전영역 크기를 비교해서 최대 크기 출력
*/