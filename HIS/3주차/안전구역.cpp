#include<iostream>
using namespace std;

/*
error : 비가 아예 오지 않은 경우가 존재하므로, 비가 온 높이의 범위를 0부터 잡아야하는데, 1부터 잡아서 실행함.
*/

int N, H = 0, ans = 0, cnt;
int map[100][100];
int visited[100][100];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };


// visited 초기화
void refresh() {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			visited[y][x] = 0;
	cnt = 0;
}

// 현재 좌표가 parameter height 높이보다 높으며, 첫 방문한 경우 방문 여부를 기록하고, 인근 노드들에 대해 재귀적으로 탐색하여 영역을 확장한다.
void dfs(int height, int y, int x) {
	if (map[y][x] > height && visited[y][x] == 0) {
		visited[y][x] = 1;
		// 인근 노드 탐색 부분
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				dfs(height, ny, nx);
			}
		}
	}
	// 이미 방문한 경우, return해서 종료시켜버리기~
	else if (visited[y][x] != 0)
		return;
}

int main() {
	cin >> N;
	// 지도 정보 입력
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			// 가장 높은 height를 저장해두기.
			if (map[y][x] > H)
				H = map[y][x];
		}

	// 비가 찰 수 있는 높이는 0부터 H까지.
	for (int i = 0; i < H; i++) {

		// dfs 동작 마다 visited 2차배열에 방문여부를 기록하므로, 매 dfs 전에 초기화 필요
		refresh();

		// 아래 2중 for문이 한 dfs 탐색 동작 덩어리.
		for(int y=0; y<N; y++)
			for (int x = 0; x < N; x++) {
				// 여기에 조건문을 작성함으로서, dfs 호출은 첫 방문하는 영역의 첫 안전지대에서만 발생하게됨.
				// 즉, 2중 for문 내의 dfs 호출마다 cnt 추가가 논리적으로 가능해진다.
				if (map[y][x] > i && visited[y][x] == 0) {
					dfs(i, y, x);
					cnt++;
				}
			}
		if (cnt > ans)
			ans = cnt;
	}
	cout << ans << endl;
}