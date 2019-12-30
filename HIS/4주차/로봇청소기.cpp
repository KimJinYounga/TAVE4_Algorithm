#include<iostream>
using namespace std;
int N, M, ans = 0;
int map[50][50];
bool visited[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int arr[4][4] = { {3, 2, 1, 0},
				  {0, 3, 2, 1},
				  {1, 0, 3, 2},
				  {2, 1, 0, 3} };
/*
0 -> 북 : 서남동북
1 -> 동 : 북서남동
2 -> 남 : 동북서남
3 -> 서 : 남동북서
*/
int my, mx, md;

void bfs(int y, int x, int dir) {
	int _dir = 0;
	visited[y][x] = true;
	map[y][x] = 2;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[arr[dir][i]];
		int nx = x + dx[arr[dir][i]];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
			if (!visited[ny][nx] && map[ny][nx] == 0) {
				_dir = arr[dir][i];
				bfs(ny, nx, _dir);
				return;
			}
		}
	}

	

	int ny = y + dy[arr[dir][1]];
	int nx = x + dx[arr[dir][1]];
	if (ny >= 0 && ny < N && nx >= 0 && nx < M)
		if (map[ny][nx] != 1)
			bfs(ny, nx, dir);
		else
			return;
}

int main() {
	cin >> N >> M;
	cin >> my >> mx >> md;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1)
				visited[y][x] = true;
		}
	bfs(my, mx, md);
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++)
			if (map[y][x] == 2)
				ans++;
	}
	cout << ans << endl;
}